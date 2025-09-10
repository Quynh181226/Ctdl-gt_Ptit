typedef struct Contact{
    char name[50];
    char phone[15];
    char email[50];
}Contact;

typedef struct TreeNode{
    Contact contact;
    struct TreeNode* left, right;
}TreeNode;

TreeNode* createTree(){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(newNode==NULL) return NULL;
    Node* cmp ctrcpy(newNode);
}
int choice=0;
do{
    printf("====Quản lý danh bạ====");
    printf("1. Thêm người vào danh bạ");
    printf("2. Hiển thị danh bạ theo ABC");
    printf("3. Tìm người theo tên");
    printf("4. Xóa người theo tên");
    printf("5. Thoát");
    switch(choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Exit program");
            break;
        default:
            printf("Invalid choice");
            break;
    }
}while(choice !== 5);