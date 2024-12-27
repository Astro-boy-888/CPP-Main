#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <immintrin.h>
#include <stdlib.h>

#define TIME_START start = std::chrono::steady_clock::now();
#define TIME_END(NAME) end = std::chrono::steady_clock::now(); \
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); \
    printf("%s: duration = %lldms\n", NAME, duration);

void array_add(float *p1, const float *p2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        p1[i] += p2[i];
    }
}

void array_add_avx2_omp(float *p1, const float *p2, size_t n) {
    if (n % 8 != 0) {
        fprintf(stderr, "The size n must be a multiple of 8.\n");
        return;
    }

    #pragma omp parallel for
    for (size_t i = 0; i < n; i += 8) {
        __m256 a = _mm256_loadu_ps(p1 + i); // 加载 p1 数组中的8个浮点数
        __m256 b = _mm256_loadu_ps(p2 + i); // 加载 p2 数组中的8个浮点数
        __m256 c = _mm256_add_ps(a, b);     // p1[i] + p2[i] 计算结果

        _mm256_storeu_ps(p1 + i, c);        // 将结果存回 p1 数组
    }
}

void array_add_avx2(float *p1, const float *p2, size_t n) {
    if (n % 8 != 0) {
        fprintf(stderr, "The size n must be a multiple of 8.\n");
        return;
    }

    for (size_t i = 0; i < n; i += 8) {
        __m256 a = _mm256_loadu_ps(p1 + i); // 加载 p1 数组中的8个浮点数
        __m256 b = _mm256_loadu_ps(p2 + i); // 加载 p2 数组中的8个浮点数
        __m256 c = _mm256_add_ps(a, b);     // p1[i] + p2[i] 计算结果

        _mm256_storeu_ps(p1 + i, c);        // 将结果存回 p1 数组
    }
}

int main() {
    const size_t n = 1000000; // 1M元素
    float *p1 = (float*)aligned_alloc(256, n * sizeof(float));
    float *p2 = (float*)aligned_alloc(256, n * sizeof(float));

    // 初始化 p1 和 p2 数组
    for (size_t i = 0; i < n; i++) {
        p1[i] = (float)i;
        p2[i] = (float)(i + 1);
    }

    std::chrono::steady_clock::time_point start, end;
    long long duration;

    // 正常的数组加法
    TIME_START;
    array_add(p1, p2, n);
    TIME_END("normal")
    printf("p1[2] = %f, p2[2] = %f, p1[n-1] = %f, p2[n-1] = %f\n", p1[2], p2[2], p1[n-1], p2[n-1]);

    // 重置 p1 和 p2 数组中的元素
    for (size_t i = 0; i < n; i++) {
        p1[i] = (float)i;
        p2[i] = (float)(i + 1);
    }

    // SIMD+OpenMP加速的向量加法
    TIME_START;
    array_add_avx2_omp(p1, p2, n);
    TIME_END("SIMD+OpenMP")
    printf("p1[2] = %f, p2[2] = %f, p1[n-1] = %f, p2[n-1] = %f\n", p1[2], p2[2], p1[n-1], p2[n-1]);

    // 重置 p1 和 p2 数组中的元素
    for (size_t i = 0; i < n; i++) {
        p1[i] = (float)i;
        p2[i] = (float)(i + 1);
    }

    // SIMD加速的向量加法
    TIME_START;
    array_add_avx2(p1, p2, n);
    TIME_END("SIMD")
    printf("p1[2] = %f, p2[2] = %f, p1[n-1] = %f, p2[n-1] = %f\n", p1[2], p2[2], p1[n-1], p2[n-1]);

    // 释放内存
    free(p1);
    free(p2);

    return 0;
}
