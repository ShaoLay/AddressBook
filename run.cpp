#include <iostream>


void show_menu();

using namespace std;

void show_menu(){
    cout << "*************************" << endl;
    cout << "***** 1. 添加联系人 *****" << endl;
    cout << "***** 2. 显示联系人 *****" << endl;
    cout << "***** 3. 删除联系人 *****" << endl;
    cout << "***** 4. 查找联系人 *****" << endl;
    cout << "***** 5. 修改联系人 *****" << endl;
    cout << "***** 6. 清空联系人 *****" << endl;
    cout << "***** 0. 退出通讯录 *****" << endl;
    cout << "*************************" << endl;
}

int main(){
    
    int select = 0;

    while(true){
        // 菜单功能
         show_menu();
        cin >> select;
        switch(select){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                cout << "欢迎下次使用!" << endl;
                return 0;
                break;
        }
    }

    return 0;
}
