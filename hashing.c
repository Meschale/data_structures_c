#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<io.h>

typedef struct bilgi {
	char *key;
	char *value;
	struct bilgi *next;
}bilgi;

typedef struct htt {
	unsigned int size;
	bilgi **arry;
}htt;
int print_char(char c)
{
	return (_write(1, &c, 1));
}
void print_str(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		print_char(str[i]);
	}
}
void print_num(int n)
{
	if (n >= 10) {
		print_num(n / 10);
	}
	print_char(n % 10 + 48);
}
void node_handler(htt *hash, bilgi *node);
unsigned int hash_maker(const char *key, unsigned int size) {
	unsigned int hash = 0, i = 0;

	while (key && key[i]) {
		hash = (hash + key[i++]) % size;
	}
	return (hash);
}

htt *h_create(unsigned int size) {
	htt *hash;

	hash = malloc(sizeof(bilgi));
	hash->arry = (bilgi**)malloc(sizeof(bilgi)*size);
	memset(hash->arry, 0, size * sizeof(bilgi));

	hash->size = size;
	return (hash);
}

int ht_set(htt *hash, const char *key, const char *value) {
	bilgi *node;

	node = malloc(sizeof(bilgi));
	node->key = _strdup(key);
	node->value = _strdup(value);
	node_handler(hash, node);

	return 0;
}

void node_handler(htt *hash, bilgi *node) {
	unsigned int i = hash_maker(node->key, hash->size);

	bilgi *temp = hash->arry[i];

	if (hash->arry[i] != NULL) {
		temp = hash->arry[i];
		while (temp != NULL) {
			if (strcmp(temp->key, node->key) == 0)
				break;
			temp = temp->next;
		}
		if (temp == NULL) {
			node->next = hash->arry[i];
			hash->arry[i] = node;
		}
		else {
            free(temp->value);
			temp->value = _strdup(node->value);
			free(node->value);
			free(node->key);
			free(node);
		}

	}
	else {
		node->next = NULL;
		hash->arry[i] = node;
	}
}

int print_hashtable(htt *hash) {
	unsigned int i;
	bilgi *bilgiptr;

	for (i = 0; i<hash->size; i++) {
		printf("%d",i);
		print_str("\n");

		bilgiptr = hash->arry[i];
		print_str("\n");
		while (bilgiptr != NULL) {
			print_str("\tkey: ");
			print_str(bilgiptr->key);
			print_str("\n\tval: ");
			print_str(bilgiptr->value);
			bilgiptr = bilgiptr->next;
			print_str("\n\t--------\n");
		}
		print_str("\tNULL\n\t--------\n");
	}
	return 0;
}
char *ht_get(htt *hash,const char *key){
	char *key_cp;
	unsigned int i;
	
	bilgi *temp;
	
	key_cp = _strdup(key);
	i = hash_maker(key, hash->size);
	temp = hash->arry[i];

	while (temp != NULL) {
		if (strcmp(temp->key, key_cp) == 0) {
			break;
		}
		temp = temp->next;
	}
	free(key_cp);

	if (temp == NULL) {
		return NULL;
	}
	return temp->value;
}
int main() {

	htt *hash;

	hash = h_create(10);

	ht_set(hash, "5", "5");
	ht_set(hash, "2", "2");
	ht_set(hash, "3", "3");
	ht_set(hash, "4", "4");
	ht_set(hash, "1", "1");
	ht_set(hash, "4", "NEW VAL 4");
	print_hashtable(hash);
	print_str(ht_get(hash, "4"));
	system("pause");
	return 0;
}
