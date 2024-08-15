# Using Test Environment

When I am practicing programming I can (I will eventually) fucked up something that can (will eventually) be critical. This is especially true for low level languages like C. Things like potential file loss, system freezing because of CPU underload, and such ~can~ will happen with some challenges or else.

I have asked `chatgpt-4o` what to do about it and two potential mitigations was mentionned that I think can be enough to avoid SHTF situations:

1. run code as non admin user without sudo permission
2. create a testing environment like Docker to run script

The first solution is per default on my current setup, but I don't know how to implement the second so I have asked the LLM to provide a synthetic table of potential sandbox env for programming:

| Method                               | Pros (+)                                                                               | Cons (-)                                                                | Documentation Link                                                                                |
| ------------------------------------ | -------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------- |
| **Virtual Machines**                 | - Full isolation from host system<br>- Can simulate different OS environments          | - Resource-intensive<br>- Slower performance compared to containers     | [VirtualBox Documentation](https://www.virtualbox.org/manual/UserManual.html)                     |
| **chroot**                           | - Lightweight<br>- Simple to set up                                                    | - Limited security<br>- Processes might escape the chroot environment   | [chroot man page](https://man7.org/linux/man-pages/man1/chroot.1.html)                            |
| **Linux Containers (LXC/LXD)**       | - Lightweight with near-native performance<br>- Flexible, closer to full OS experience | - Slightly more complex than Docker<br>- Less isolation than VMs        | [LXD Documentation](https://linuxcontainers.org/lxd/docs/master/)                                 |
| **Firejail**                         | - Easy to use<br>- Minimal performance impact                                          | - Not as comprehensive as Docker or VMs<br>- Best for simple sandboxing | [Firejail Documentation](https://firejail.wordpress.com/documentation-2/)                         |
| **QEMU User Emulation**              | - High degree of isolation<br>- Can emulate different CPU architectures                | - Performance overhead<br>- More complex setup                          | [QEMU Documentation](https://www.qemu.org/documentation/)                                         |
| **Seccomp**                          | - Fine-grained control over process capabilities<br>- Lightweight                      | - Requires advanced knowledge<br>- Not a full sandbox                   | [Seccomp Documentation](https://www.kernel.org/doc/html/latest/userspace-api/seccomp_filter.html) |
| **User Namespaces and Capabilities** | - Strong isolation<br>- Allows running with limited privileges                         | - Complex to set up<br>- Requires understanding of Linux capabilities   | [Linux Namespaces Documentation](https://man7.org/linux/man-pages/man7/namespaces.7.html)         |
| **BPF and eBPF**                     | - High security<br>- Enforce strict policies at the kernel level                       | - Highly complex<br>- Requires deep kernel knowledge                    | [eBPF Documentation](https://ebpf.io/what-is-ebpf/)                                               |
