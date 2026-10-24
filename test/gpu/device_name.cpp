/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015-2026 Advanced Micro Devices, Inc. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <migraphx/gpu/context.hpp>
#include <migraphx/gpu/device_name.hpp>
#include "test.hpp"

#if !MIGRAPHX_USE_HIPBLASLT
TEST_CASE(default_rocblas_without_hipblaslt)
{
    EXPECT(migraphx::gpu::gfx_default_rocblas());
    EXPECT(not migraphx::gpu::hipblaslt_supported());
    migraphx::gpu::context ctx;
    EXPECT(migraphx::gpu::gfx_default_rocblas(ctx));
    EXPECT(not migraphx::gpu::hipblaslt_supported(ctx));
}
#endif

int main(int argc, const char* argv[]) { test::run(argc, argv); }
