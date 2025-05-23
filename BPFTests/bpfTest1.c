#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#define SEC(NAME) __attribute__((section(NAME), used))

SEC("tracepoint/syscall/sys_enter_execve")
int bpf_prog(void *ctx){

	char msg[] = "Hello, bpf world!";
	bpf_trace_printk(msg, sizeof(msg));
	return 0;

}

char _license[] SEC("license") = "GPL";
