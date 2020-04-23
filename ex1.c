int soma(int a, int b) {
	int c = a + b;

	return c;
}

int main() {
	int x = 2, 
	    y = 3,
	    z = soma(x, y);

	printf("soma = %d\n", z);
	return 0;    
}