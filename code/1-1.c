#include <stdio.h>

struct S1 {
	char c;
	int i;
	long long l;
};

#pragma pack(push, 1)
struct S2 {
	char c;
	int i;
	long long l;
};
#pragma pack(pop)

int main() {
	struct S1 s1;
	struct S2 s2;
	printf("%zu %zu\n", sizeof(s1), sizeof(s2));
}
