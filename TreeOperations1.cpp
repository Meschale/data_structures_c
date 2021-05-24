#include<stdio.h>
#include<stdlib.h>

typedef struct Btree{
	int info;
	int id;
	Btree* left;
	Btree* right; 
}Btree;

Btree* root = NULL;

bool insertion(Btree* node);
Btree* createNode();
bool deleteNode(Btree* node,int info);
int searchNode(Btree* node,int info);
void traverseInorder(Btree* node);
void traversePostorder(Btree* node);
void traversePreorder(Btree* node);
int sum(Btree* node,int summ);
int main(){
	int choice;
	bool result;
	int x;
	do{
		printf("\n****Tree Operations****\n");
		printf("1-Inserting Node..\n");
		printf("2-Deleting Node..\n");
		printf("3-Searching Node..\n");
		printf("4-Traverse(Inorder) Node..\n");
		printf("5-Traverse(Preorder) Node..\n");
		printf("6-Traverse(Postorder) Node..\n");
		printf("7-Sum of Nodes..\n");
		printf("8-Quit..\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				result = insertion(createNode());
				result == true ? printf("Successfull.\n") : printf("Error.\n");
				break;
			case 2:
				printf("Which item(with info) are you looking for :");
				scanf("%d",&x);
				result = deleteNode(root,x);
				result == true ? printf("Successfull.\n") : printf("Error.\n");
				break;
			case 3:
				printf("Which item(with info) are you looking for :");
				scanf("%d",&x);
				printf("the id of %d is : %d\n",x,searchNode(root,x));
				break;
			case 4:
				traverseInorder(root);
				break;
			case 5:
				traversePreorder(root);
				break;
			case 6:
				traversePostorder(root);
				break;
			case 7:
				printf("Sum of nodes : %d",sum(root,0));
				break;
			case 8:
				choice = 5;
				break;
			default:
				printf("Keycode error, try again..\n");
				continue;
		}
	}while(choice != 8);
	
	return 0;
}

bool insertion(Btree* node){
	Btree* temp;
	temp = root;
	if(root == NULL){
		root = node;
		return true;
	}
	else{
		while(temp->info != node->info){
			if(node->info < temp->info){
				if(temp->left != NULL){
				    temp = temp->left;	
				}
			    else{
			        temp->left = node;
				    return true;
				} 
			}
			else{
				if(temp->right != NULL){
				    temp = temp->right;	
				}
			    else{
			        temp->right = node;
				    return true;
				} 
			}
		}
	}
	
}

Btree* createNode(){
	Btree* node;
	node = (Btree*)malloc(sizeof(Btree));
	printf("Plese enter the information :");
	scanf("%d",&node->info);
	printf("Plese enter the id :");
	scanf("%d",&node->id);
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool deleteNode(Btree* node,int info){
	Btree* q,*qa,*qc,*s,*sa;
	if(node==NULL){
	    return false;
	}
	q = node;
	qa = NULL;
	while(( q != NULL) && (q->info != info)){
		qa=q;
		if(q->info > info){
			q = q->left;
		}
		else
			q = q->right;
	}
	if(q == NULL){//eleman yoksa
		return false;
	}
	if((q->left != NULL) && (q->right != NULL)){//2 çocuðu var
		s = q->left;
		sa = q;
		while(s->right != NULL){
			sa = s;
			s = s->right;
		}
		q->info = s->info;
		q->id = s->id;
		q = s;
		qa = sa;
	}//þimdi en fazla 1 çocugu var
	if(q->left != NULL){
		qc = q->left;
	}
	else{
		qc = q->right;
	}
	if(q == node){//silinecek olan rootsa ve 2 çocugu yoksa
		root = qc;
	}
	else{
		if(q == qa->left){
			qa->left = qc;
		}
		else{
			qa->right = qc;
		}
	}
	free(q);
	return true;
}

int searchNode(Btree* node,int info){
	if(node != NULL){
	    if(node->info < info){
	 	   searchNode(node->right,info);
	    }
	    else if(node->info > info){
		    searchNode(node->left,info);
    	}
	    else 
            return node->id;
   }
   else
       return -1;
}
void traverseInorder(Btree* node){
	if(node != NULL){
		traverseInorder(node->left);
		printf("%d ",node->info);
		traverseInorder(node->right);
	}
}
void traversePreorder(Btree* node){
	if(node != NULL){
		printf("%d ",node->info);
		traversePreorder(node->left);
		traversePreorder(node->right);
	}
}
void traversePostorder(Btree* node){
	if(node != NULL){
		traversePostorder(node->left);
		traversePostorder(node->right);
		printf("%d ",node->info);
	}
}
int sum(Btree* node,int summ){
	if(node == NULL)
	    return summ;
	summ++;
	summ = sum(node->left,summ);
	summ = sum(node->right,summ);
}
