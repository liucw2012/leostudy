/*
 * drivertest.cpp
 * Vector addition (host code)
 *
 * Andrei de A. Formiga, 2012-06-04
 */

#include <stdio.h>
#include <stdlib.h>

#include <cuda.h>
#include <builtin_types.h>


// This will output the proper CUDA error strings
// in the event that a CUDA host call returns an error
#define checkCudaErrors(err)  __checkCudaErrors (err, __FILE__, __LINE__)

inline void __checkCudaErrors( CUresult err, const char *file, const int line )
{
    if( CUDA_SUCCESS != err) {
        fprintf(stderr,
                "CUDA Driver API error = %04d from file <%s>, line %i.\n",
                err, file, line );
        exit(-1);
    }
}

// --- global variables ----------------------------------------------------
CUdevice   device;
CUcontext  context;
CUmodule   module;
CUfunction function;
size_t     totalGlobalMem;



// --- functions -----------------------------------------------------------
void initCUDA()
{
    int deviceCount = 0;
    CUresult err = cuInit(0);
    int major = 0, minor = 0;

    cuDeviceGetCount(&deviceCount);
    printf("I got GPU count:%d\r\n", deviceCount);
    if (deviceCount == 0) {
        fprintf(stderr, "Error: no devices supporting CUDA\n");
        exit(-1);
    }

}

int main(int argc, char **argv)
{
    printf("- Initializing...\n");
    initCUDA();

    return 0;
}
