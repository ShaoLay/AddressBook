#include <iostream>
#include <string>
#define MAX 1000 // 最大人数


// void show_menu();
// void add_person(address_books *abs);
// void show_person(address_books *abs);
// int is_exist(address_books *abs, string name);

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

void show_person(address_books *abs){
    if(abs->m_size == 0){
        cout << "没有任何联系人!" << endl;
        system("clear");
    }else{
        for(int i = 0; i < abs->m_size; i++){
            cout << "姓名: " << abs->person_array[i].m_name << endl;
            cout << "性别: " << (abs->person_array[i].m_sex == 1 ? "男": "女") << endl;
            cout << "年龄: " << abs->person_array[i].m_age << endl;
            cout << "电话: " << abs->person_array[i].m_phone << endl;
            cout << "住址: " << abs->person_array[i].m_addr << endl;
        }
    }
}

int is_exist(address_books *abs, string name){
    for(int i = 0; i < abs->m_size; i++){
        if(abs->person_array[i].m_name == name){
            return i;
        }
    }
    return -1;
}

void delete_person(address_books *abs){
    cout << "请输入您要删除的联系人: " << endl;
    string name;
    cin >> name;
    int ret = is_exist(abs, name);
    if(ret != -1){
        for(int i = ret; i<abs->m_size; i++){
            abs->person_array[i] = abs->person_array[i + 1];
        }
        abs->m_size--;
        cout << "删除成功!" << endl;
    }else{
        cout << "查无此人!" << endl;
    }
}

void find_person(address_books *abs){
    cout << "请输入您要查询的联系人:    " << endl;
    string name;
    cin >> name;
    int ret = is_exist(abs, name);
    if(ret != -1){
        cout << "姓名: " << abs->person_array[ret].m_name << "\t";
        cout << "年龄: " << abs->person_array[ret].m_age << "\t";
        cout << "性别: " << (abs->person_array[ret].m_sex == 1 ? "男":"女") << "\t";
        cout << "电话: " << abs->person_array[ret].m_phone << "\t";
        cout << "地址: " << abs->person_array[ret].m_addr << "\t";
        cout << endl;
    }else{
        cout << "查无此人!" << endl;
    }
}

void modify_person(address_books *abs){
    cout << "请输入你要修改的联系人: " << endl;
    string name;
    cin >> name;
    int ret = is_exist(abs, name);
    if(ret != -1) {
        string name, phone, address;
        int age = 0, sex = 0;
        cout << "请输入姓名:" << endl;
        cin >> name;
        abs->person_array[ret].m_name = name;
        cout << "请输入性别: " << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;
        while(true){
            cin >> sex;
            if(sex == 1 || sex == 2){
                abs->person_array[ret].m_sex = sex;
                break;
            }
            cout << "输入有误, 请重新输入!" << endl;
        }
        while(true){
            cout << "请输入年龄: ";
            cin >> age;
            if(age >= 0 && age <= 120){       
                abs->person_array[ret].m_age = age;
                break;
            }
        }
        cout << "请输入地址: ";
        cin >> address;
        abs->person_array[ret].m_addr = address;
        cout << "请输入电话:";
        cin >> phone;
        abs->person_array[ret].m_phone = phone;
        cout << "修改成功!" << endl;
    }else{
        cout << "查无此人!" << endl;
    }
}

void clean_person(address_books *abs){
    abs->m_size = 0;
    cout << "通讯录已清空!" << endl;
}

int main(){
    
    address_books abs;
    abs.m_size = 0;

    int select = 0;

    while(true){
        // 菜单显示功能
        show_menu();
        cin >> select;
        switch(select){
            case 1:
                add_person(&abs);
                break;
            case 2:
                show_person(&abs);
                break;
            case 3:
                delete_person(&abs);
                break; 
            case 4:
                find_person(&abs);
                break;
            case 5:
                modify_person(&abs);
                break;
            case 6:
                clean_person(&abs);
                break;
            case 0:
                cout << "欢迎下次使用!" << endl;
                return 0;
                break;
        }
    }

    return 0;
}
