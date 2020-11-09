#include <iostream>
#include <string>
#define MAX 1000 // 最大人数


void show_menu();

using namespace std;

// 联系人结构体
struct person{
    string m_name;
    int m_sex;
    int m_age;
    string m_phone;
    string m_addr;
};

// 通讯录结构体
struct address_books{
    struct person person_array[MAX];
    int m_size; // 通讯录人员个数
};


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

void add_person(address_books *abs){

    if(abs->m_size == MAX){
        cout << "通讯录已满,无法添加!!" << endl;
        return;
    }else{
        string name;
        cout << "请输入姓名: " << endl;
        cin >> name;
        abs->person_array[abs->m_size].m_name = name;
    }
    cout << "请输入性别: " << endl;
    cout << "1 --- 男" << endl;
    cout << "2 --- 女" << endl;
    int sex = 0;
    while(true){
        cin >> sex;
        if(sex == 1 || sex == 2){
            abs->person_array[abs->m_size].m_sex = sex;
            break;
        }
        cout << "输入有误!请重新输入!" << endl;
    }
    cout << "请输入年龄:" << endl;
    int age = 1;
    while(true){
        cin >> age;
        if(age >= 1 && age <= 120){
            abs->person_array[abs->m_size].m_age = age;
            break;
        }
        cout << "年龄有误!请重新输入!" << endl;
    }
    cout << "请输入电话号码: " << endl;
    string phone;
    cin >> phone;
    abs->person_array[abs->m_size].m_phone = phone;
    cout << "请输入地址: " << endl;
    string address;
    cin >> address;
    abs->person_array[abs->m_size].m_addr = address;
    abs->m_size++;
    cout << "添加成功!" << endl;
    system("clear");
}

int main(){
    
    address_books abs;
    abs.m_size = 0;

    int select = 0;

    while(true){
        // 菜单功能
        show_menu();
        cin >> select;
        switch(select){
            case 1:
                add_person(&abs);
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
