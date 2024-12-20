#include<stdio.h>
#include<string.h>
struct Dish{
	int id;
	char name[20];
    int price;
};

int main(){
	struct Dish menu[100]={
	{1,"cho",200},
	{2,"meo",150},
	{3,"lon",100},
	{4,"ga",70},
	{5,"bo",500}
	};
	int n=5;
	int d=5;
	int choice;
	do{
		printf("\n            menu\n");
		printf("1. In ra giá tr? các ph?n t? có trong menu món an\n");
		printf("2. Thêm m?t ph?n t? vào v? trí ch? d?nh\n");
		printf("3. S?a m?t ph?n t? ? v? trí ch? d?nh\n");
		printf("4. Xóa m?t ph?n t? ? v? trí ch? d?nh\n");
		printf("5. S?p x?p các ph?n t? giam dan theo gia\n");
		printf("6. Tìm ki?m ph?n t? theo name nh?p vào\n");
		printf("7. Thoát\n");
		printf("\n lua chon cua ban la:");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				for(int i=0;i<n;i++){
					printf("\n%d.",i+1);
					printf("%s:",menu[i].name);
					printf("%d",menu[i].price);
				}
				break;
			}
			case 2:{
				fflush(stdin);
				d++;
				menu[n].id=d;
				printf("\nnhap phan tu muon them\n");
				printf("nhap ten mon:");
				fgets(menu[n].name,sizeof(menu[n].name),stdin);
				menu[n].name[strcspn(menu[n].name, "\n")] = '\0';
				printf("nhap gia tien:");
				scanf("%d",&menu[n].price);
				fflush(stdin);
				n++;
				break;
			}
			case 3: {
                int sua;
                printf("nhap vi tri can sua:");
                scanf("%d", &sua);
                fflush(stdin);
                if (sua < 1 || sua > n) {
                    printf("khong hop le\n");
                } 
				else {
                    printf("\nNhap ten moi: ");
                    fgets(menu[sua-1].name, sizeof(menu[sua-1].name), stdin);
                    menu[sua-1].name[strcspn(menu[sua-1].name, "\n")] = '\0';
                    printf("\nNhap gia moi: ");
                    scanf("%d", &menu[sua].price);
                    fflush(stdin);
                }
                break;
			}
			case 4:{
				menu[n-1] = menu[n];
				n--;
				break;
			}
			case 5:{
				for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (menu[i].price > menu[j].price) {
                            struct Dish temp = menu[i];
                            menu[i] = menu[j];
                            menu[j] = temp;
                        }
                    }
                }
				break;
			}
			case 6: {
				fflush(stdin);
                char search[20];
                printf("\nNhap ten mon can tim:");
                fgets(search, sizeof(search), stdin);
                search[strcspn(search, "\n")] = '\0';
                printf("\nmon o vi tri:");
                int co = 0;
			    for (int i = 0; i < n; i++) {
			        if (strcmp(menu[i].name, search) == 0) {
			            printf("%d ", i + 1);
			            co = 1;
			        }
			    }
				if (co== 0) {
			        printf("Khong tim thay mon an.\n");
			    }
                break;
            }
            case 7:{
                printf("Thooat\n");
                break;
            }
            default:{
                printf("Lua chon ko hop le\n");
                break;
            }
	    }
	}while(choice!=7);
	
	return 0;
}






