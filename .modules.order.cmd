cmd_/home/dima/LinuxKernelProgramming/modules.order := {   echo /home/dima/LinuxKernelProgramming/mymodule.ko; :; } | awk '!x[$$0]++' - > /home/dima/LinuxKernelProgramming/modules.order
