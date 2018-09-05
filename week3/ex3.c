#include <stdio.h>

struct linked_list {
	struct node * head;
	int size;
};

struct node {
	int value;
	struct node * next;
};

void insert_node(struct linked_list * list, int value) {\
	if(!list->size) {
		struct node * n = (struct node *) malloc(sizeof(struct node));
		n->value = value;
		list->head = n;
		list->size = 1;
	}else {
		struct node * n = list->head;
		while(n->next != NULL) {
			n = n->next;
		}
		struct node * new = (struct node *) malloc(sizeof(struct node *));
		new->value = value;
		n->next = new;
		list->size++;
	}

}

void print_list(struct linked_list *list) {
	if(list->size != 0){
		struct node * n = list->head;
		while(n->next != NULL) {
			printf("%d ", n->value);
			n = n->next;
		}
		printf("%d\n", n->value);
	}
}

void delete_node(struct linked_list *list, int index) {
	if(index >= list->size)
		return;
	struct node * n = list->head;
	int i = 0;
	while(n->next != NULL) {
		if(i == index-1) {
			struct node * temp = n->next;
			n->next = n->next->next;
			free(temp);
			break;
		}
		i++;
		n = n->next;
	}
}

int main() {
	struct linked_list list;
	list.size = 0;
	for(int i = 0; i < 10; i++) {
		insert_node(&list, i);
	}
	print_list(&list);
	delete_node(&list, 5);
	print_list(&list);
	return 0;
}
