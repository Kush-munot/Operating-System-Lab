grep -c processor /proc/cpuinfo
grep 'cpu cores' /proc/cpuinfo | uniq
grep 'cpu MHz' /proc/cpuinfo
grep 'MemTotal' /proc/meminfo
grep 'MemFree' /proc/meminfo
vmstat -f
grep 'ctxt' /proc/stat
