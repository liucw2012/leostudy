import os
import sys
import pynvml as N

MB = 1024 * 1024

def get_usage(device_index, my_pid):
    N.nvmlInit()

    handle = N.nvmlDeviceGetHandleByIndex( int(device_index))

    usage = [nv_process.usedGpuMemory // MB for nv_process in
             N.nvmlDeviceGetComputeRunningProcesses(handle) + N.nvmlDeviceGetGraphicsRunningProcesses(handle) if
             nv_process.pid == my_pid]

    if len(usage) == 1:
        usage = usage[0]
    else:
        raise KeyError("PID not found")

    return usage

if __name__ == "__main__":
   print(get_usage(sys.argv[1], sys.argv[2]))
