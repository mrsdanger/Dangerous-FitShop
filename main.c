//PROGRAMMERS: TAMILLY&&LARISSA - 18/10/2019 ; Version 1.0 - Dangerous FitShop 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TS 50
#define T 2
#define admin 256
//Build of the STRUCTS 
typedef struct product{
	int code;
	float value_to_sell, value_to_buy;
	char name[TS], product_description[TS];
}PRODUCT;

typedef struct address{
	char zip[TS], street[TS], city[TS], state[TS]; 
	int number;
}ADDRESS;

typedef struct client{
	int id, age;
	char name[TS], birthday[TS], cpf[TS], email[TS], phone[TS]; 
	ADDRESS address;
}CLIENT;

typedef struct purchase{
	int id_client, code_product;
	char purchase_description[TS], purchase_status[TS];
}PURCHASE;

typedef struct order{
	int id_client, code_product;
	float shipping_value;
	char order_description[TS], order_status[TS];
}ORDER;
//Defining FUNCTIONS
int addProducts(PRODUCT *pointer);
int addClients(CLIENT *pointer);
int addPurchase(PURCHASE *pointer);
int addOrder(ORDER *pointer);
void showProducts();
void showClients();
void showPurchase();
void showOrder();
void menuAdmin();
int menuAdd();
int menuShow();
int menuUpdate();
int menuDelete();
void bills();
//>>>>>MAIN
int main(void){
	//Declaring simple VARIABLES
	char user[TS];
	int password, main_option=-1;
	//Welcome and system log in
	printf("**  Dangerous FitShop   **\n");
	printf("USER: ");
	gets(user);
	printf("PASSWORD: ");
	scanf("%d", &password);
	if((strcmp(user, "admin")==0) && password==256){
		menuAdmin();
	}
	else{
		printf("Invalid user or password! Please, for your safety, try again later.");
	}
	
	return 0;
}

//>>>>>>>>>>>>>>>>>>>ADD AREA<<<<<<<<<<<<<<<<<<
int addProducts(PRODUCT *pointer){
	int i, o;
	FILE *file_products;
	printf("** ADD PRODUCTS **\n\n");
	for(i=0;i<T;i++){
		file_products = fopen("products.txt", "a");
		printf("Code: ");
		scanf("%d", &pointer->code);
		fflush(stdin);
		printf("Name: ");
		gets(pointer->name);
		printf("Short description: ");
		gets(pointer->product_description);
		fflush(stdin);
		printf("Value from provider: ");
		scanf("%f", &pointer->value_to_buy);
		printf("** 1 - Calculate value to sell | 0 - Continue **\n");
		scanf("%d", &o);
		if(o == 1){
			float value = pointer->value_to_buy * 0,3;
			printf("** Calculated value: %.2f **\n", (pointer->value_to_buy + value));
			pointer->value_to_sell = (pointer->value_to_buy + value);
		}else{
			printf("Value to sell: ");
			scanf("%f", &pointer->value_to_sell);
		}
		fprintf(file_products, "%d ", pointer->code);
		fprintf(file_products, "%s ", pointer->name);
		fclose(file_products);
	}
	return 1;
}

void addAddress(ADDRESS *pointer){
	
}

int addClients(CLIENT *pointer){
	int i, o;
	FILE *file_clients;
	printf("** ADD CLIENTS **\n\n");
	for(i=0;i<T;i++){
		file_clients = fopen("clients.txt", "a");
		printf("ID: ");
		scanf("%d", &pointer->id);
		fflush(stdin);
		printf("Name: ");
		gets(pointer->name);
		printf("CPF: ");
		gets(pointer->cpf);
		fflush(stdin);
		printf("E-mail: ");
		gets(pointer->email);//////////////////////////////////////////////////////////////STOPPED HERE 
		printf("Value from provider: ");
		scanf("%f", &pointer->value_to_buy);
		printf("** 1 - Calculate value to sell | 0 - Continue **\n");
		scanf("%d", &o);
		if(o == 1){
			float value = pointer->value_to_buy * 0,3;
			printf("** Calculated value: %.2f **\n", (pointer->value_to_buy + value));
			pointer->value_to_sell = (pointer->value_to_buy + value);
		}else{
			printf("Value to sell: ");
			scanf("%f", &pointer->value_to_sell);
		}
		fprintf(file_products, "%d ", pointer->code);
		fprintf(file_products, "%s ", pointer->name);
		fclose(file_products);
	}
	return 1;
}


//>>>>>MENU AREA
int menuAdd(){
	int o;
	printf("1-ADD PRODUCTS\n2-ADD CLIENTS\n3-ADD PURCHASE\n4-ADD ORDER\n->");
	scanf("%d", &o);
	if(o > 0 && o < 5)
		return o;
	else
		return -1;
} 

int menuShow(){
	int o;
	printf("1-SHOW PRODUCTS\n2-SHOW CLIENTS\n3-SHOW PURCHASES\n4-SHOW ORDERS\n->");
	scanf("%d", &o);
	if(o > 0 && o < 5)
		return o;
	else
		return -1;
}

int menuUpdate(){
	int o;
	printf("1-UPDATE PRODUCT\n2-UPDATE CLIENT\n3-UPDATE PURCHASE\n4-UPDATE ORDER\n->");
	scanf("%d", &o);
	if(o > 0 && o < 5)
		return o;
	else
		return -1;
}

int menuDelete(){
	int o;
	printf("1-DELETE PRODUCT\n2-DELETE CLIENT\n3-DELETE PURCHASE\n4-DELETE ORDER\n->");
	scanf("%d", &o);
	if(o > 0 && o < 5)
		return o;
	else
		return -1;
}

void bills(){
}
//>>>>>>>>>>>>>>>>>>>>MAIN MENU<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void menuAdmin(){
	//Declaring simple VARIABLES
	int menu_option=-1;
	//Declaring important VARIABLES
	PRODUCT products[T];
	CLIENT clients[T];
	PURCHASE purchases[T];
	ORDER orders[T];
	int s = 4 * T;
	int file_names[s], file_index=0;
	
	printf("**   WELCOME, ADMIN   **\n");
	do{
		printf("1-ADD\n2-SHOW\n3-UPDATE\n4-DELETE\n5-BILLS\n6-PROGRAM INFORMATIONS\n0-EXIT\n->");
		scanf("%d", &menu_option);
		switch(menu_option){
			case 1:
				int op = menuAdd();
				if(op > 0){
					switch(op){
						//>>>>>>>>>>ADD PRODUCTS
						case 1:
							files_name[file_index] = addProducts(&products[0]);
							file_index++;
							break;
						//>>>>>>>>>>ADD CLIENTS
						case 2:
							files_name[file_index] = addClients(&clients[0]);
							file_index++;
							break;
						//>>>>>>>>>>ADD PURCHASE
						case 3:
							files_name[file_index] = addPurchase(&purchases[0]);
							file_index++;
							break;
						//>>>>>>>>>>ADD ORDER
						case 4:
							files_name[file_index] = addOrder(&orders[0]);
							file_index++;
							break;
					}			
				}
				else{
					printf("Invalid option!\n");
				}
				break;
			case 2:
				int op = menuShow();
				if(op > 0){
					switch(op){
						//>>>>>>>>>>SHOW PRODUCTS
						case 1:
							showProducts(&products[0]);
							break;
						//>>>>>>>>>>SHOW CLIENTS
						case 2:
							showClients(&clients[0]);
							break;
						//>>>>>>>>>>SHOW PURCHASE
						case 3:
							showPurchase(&purchases[0]);
							break;
						//>>>>>>>>>>SHOW ORDER
						case 4:
							showOrder(&orders[0]);
							break;
					}			
				}
				else{
					printf("Invalid option!\n");
				}
				break;
			case 3:
				int op = menuUpdate();
				if(op > 0){
					switch(op){
						//>>>>>>>>>>UPDATE PRODUCTS
						case 1:
							updateProducts(&products[0]);
							break;
						//>>>>>>>>>>UPDATE CLIENTS
						case 2:
							updateClients(&clients[0]);
							break;
						//>>>>>>>>>>UPDATE PURCHASE
						case 3:
							updatePurchase(&purchases[0]);
							break;
						//>>>>>>>>>>UPDATE ORDER
						case 4:
							updateOrder(&orders[0]);
							break;
					}			
				}
				else{
					printf("Invalid option!\n");
				}
				break;
			case 4:
				int op = menuDelete();
				if(op > 0){
					switch(op){
						//>>>>>>>>>>DELETE PRODUCTS
						case 1:
							deleteProducts(&products[0]);
							break;
						//>>>>>>>>>>DELETE CLIENTS
						case 2:
							deleteClients(&clients[0]);
							break;
						//>>>>>>>>>>DELETE PURCHASE
						case 3:
							deletePurchase(&purchases[0]);
							break;
						//>>>>>>>>>>DELETE ORDER
						case 4:
							deleteOrder(&orders[0]);
							break;
					}			
				}
				else{
					printf("Invalid option!\n");
				}
				break;
			case 5:
				bills();
			case 6:
				printf("This program was first made at 18/10/2019, IFAL-Campus Arapiraca. Programmers: Tamilly Nascimento and Larissa Clara.\n");
				printf("Contact informations:\nTAMILLY: contactamilly@gmail.com\nWEBSITE: tamillyn.000webhostapp.com\nThank you for reading.");
		}
	}while(menu_option != 0);
}
