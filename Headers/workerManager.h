//
// Created by huang on 2024/6/6.
//


#pragma once   //防止头文件重复包含
#include "iostream"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include "fstream"
#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager{
public:
    //构造函数
    WorkerManager();

    //显示菜单
    void Show_Menu();

    //退出系统
    void ExitSystem();

    //添加职工
    void Add_Emp();

    //保存文件
    void save();

    //统计职工人数
    int get_EmpNum();

    //初始化员工
    void init_Emp();

    //显示职工信息
    void show_Emp();

    //删除职工
    void Del_Emp();

    //按照职工编号判断是否存在，若存在返回职工在数组中的位置，不存在返回-1
    int IsExist(int id);

    //修改职工
    void Mod_Emp();

    //查找职工
    void Find_Emp();

    ~WorkerManager();

public:
    int m_EmpNum; //职工人数

    Worker ** m_EmpArray;  //记录职工数组指针

    bool m_FileIsEmpty; //标志文件是否为空
};

WorkerManager::WorkerManager() {

    ifstream ifs;  //输出文件流
    ifs.open(FILENAME,ios::in);

    //文件不存在情况
    if (!ifs.is_open()){
        cout << "文件不存在" << endl;
        //初始化人数
        this->m_EmpNum = 0;

        //初始化数组指针
        this->m_EmpArray = NULL;

        //初始化文件为空标志
        this->m_FileIsEmpty = true;

        ifs.close();
        return;
    }

    //文件存在，且没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof()){
        cout << "文件为空!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    //文件存在且有数据，获取人数
    int num = this->get_EmpNum();
    cout << "职工个数为 : " << num << endl;
    this->m_EmpNum = num; //更新职工人数

    //根据职工数量创建数组
    this->m_EmpArray = new Worker * [this->m_EmpNum];
    //初始化职工数组
    init_Emp();
}

WorkerManager::~WorkerManager() {
    if (this->m_EmpArray != NULL)
        delete[] this->m_EmpArray;
}
void WorkerManager::Show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}


//添加职工的实现
void WorkerManager::Add_Emp() {
    cout << "请输入增加的职工数量" << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0){
        //采用可变长数组的形式放入新职工，新开辟一个数组来存放替代原来的旧数组

        //计算新空间的大小
        int newSize = this->m_EmpNum + addNum;

        //开辟新空间
        Worker ** newSpace = new Worker * [newSize];

        //将原空间下内容存放到新空间下
        if (this->m_EmpNum != NULL){
            for (int i = 0; i < this->m_EmpNum; ++i) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //输入新数据
        for (int i = 0; i < addNum; ++i) {
            int id;
            string name;
            int dSelect;

            cout<< "请输入第 " << i + i << " 个新职工编号 ：" <<endl;
            cin >> id;

            cout<< "请输入第 " << i + 1 << "个新职工姓名 : " <<endl;
            cin >> name;

            cout << "请选择g该职工的岗位 : " << endl;
            cout << "1、普通职工" <<endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            //创建新职工
            Worker *worker = NULL;
            switch (dSelect) {
                case 1:   //普通职工
                    worker = new Employee(id,name,1);
                    break;
                case 2: //经理
                    worker = new Manager(id,name,2);
                    break;
                case 3: //老板
                    worker = new Boss(id,name,3);
                    break;
                default:
                    break;
            }

            newSpace[this->m_EmpNum + i] = worker;
        }
        //释放原有空间
        delete[] this->m_EmpArray;

        //管理系统的职工信息数组指向新开的数组中
        this->m_EmpArray = newSpace;

        //更新职工数量
        this->m_EmpNum = newSize;

        //更新职工不为空的标志
        this->m_FileIsEmpty = false;

        //提示添加成功
        cout << "成功添加" << addNum << "名新职工！" << endl;

        //将数据写入文件中
        this->save();
    } else{
        cout << "输入有误" <<endl;
    }

    system("pause");
    system("cls");
}


//退出系统
void WorkerManager::ExitSystem() {
    cout << "欢迎下次使用" <<endl;
    system("pause");
    exit(0);
}

void WorkerManager::save() {
    ofstream ofs;  //输入文件流
    ofs.open(FILENAME,ios::out);

    for (int i = 0; i < this->m_EmpNum; ++i) {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

int WorkerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId){
        //记录人数
        num++;
    }
    ifs.close();

    return num;
}


void WorkerManager::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    cout<<"初始化" << endl;
    int id;
    string name;
    int dId;
    this->m_FileIsEmpty = false;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId){
        Worker *worker = NULL;

        //根据不同的部门id进行角色创建
        if (dId == 1) {   //普通职工
            worker = new Employee(id,name,dId);
        } else if (dId == 2) {  //经理
            worker = new Manager(id,name,dId);
        } else if (dId == 3) { //老板
            worker = new Boss(id,name,dId);
        }

        //将创建好的对象放入对象数组中
        this->m_EmpArray[index++] = worker;

    }

}

//显示职工
void WorkerManager::show_Emp() {
    if (this->m_FileIsEmpty)
        cout << "文件不存在或记录为空" << endl;
    else
        for (int i = 0; i < m_EmpNum; ++i) {
            //调用数组中每个对应职工的显示个人信息的函数
            this->m_EmpArray[i]->showInfo();
        }
    system("pause");
    system("cls");
}

//判断职工是否存在
int WorkerManager::IsExist(int id) {
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; ++i) {
        if (this->m_EmpArray[i]->m_Id == id){
            index = i;
            break;
        }
    }
    return index;
}


//删除职工
void WorkerManager::Del_Emp() {
    if (this->m_FileIsEmpty)
        cout << "文件不存在或记录为空 ! " << endl;
    else{
        //按职工编号删除
        cout<< "请输入想要删除的职工号" << endl;

        int id = 0;
        cin >> id;


        int index  = this->IsExist(id);

        if (index != -1){  //表示需要删除的职工是存在的
            for (int i = index; i < this->m_EmpNum -1; ++i) {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
                //需要删除的节点后面的元素依次向前移动覆盖即可实现删除
            }
            this->m_EmpNum--;

            this->save(); //删除数据后同步到文件中
            cout << "删除成功!" <<endl;
        } else{
            cout << "删除失败！"<< endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Mod_Emp() {
    if (this->m_FileIsEmpty)
        cout<< "文件不存在或记录为空!" <<endl;
    else{
        cout<< "请输入修改职工的编号" <<endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1){   //表示需要修改的职工存在

            delete this->m_EmpArray[ret];  //删除原来的职工信息

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到: " << id << "号员工，请输入新职工号" << endl;
            cin >> newId;

            cout << "请输入新姓名 ：" << endl;
            cin >> newName;

            cout << "请输入岗位 ： " << endl;
            cout << "1、普通职工" <<endl;
            cout << "2、经理" <<endl;
            cout << "3、老板" <<endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(newId,newName,dSelect);
                    break;
                case 2:
                    worker = new Manager(newId,newName,dSelect);
                    break;
                case 3:
                    worker = new Boss(newId,newName,dSelect);
                    break;
                default:
                    break;
            }

            //更新数据到数组中
            this->m_EmpArray[ret] = worker;

            cout << "修改成功!" <<endl;

            //保存数据
            this->save();
        } else{
            cout << "查无此人" << endl;
        }

    }

    system("pause");
    system("cls");
}

//查找员工
void WorkerManager::Find_Emp() {
    if (this->m_FileIsEmpty)
        cout << "文件不存在或记录为空" <<endl;
    else{
        cout << "请输入查找方法" << endl;
        cout << "1.按职工编号查找" <<endl;
        cout << "2.按姓名查找" << endl;


        int select = 0;
        cin >> select;

        if (select == 1){   //按职工工号查找
            int id;
            cout << "请输入查找的职工编号" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1){
                cout << "查找成功！该职工信息如下 : " << endl;
                this->m_EmpArray[ret]->showInfo();
            } else
                cout << "查无此人" <<endl;
        } else if (select == 2) {  //按姓名查找
            string name;
            cout << "请输入查找的姓名" << endl;

            cin >> name;

            bool flag = false; //查找到的标志
            for (int i = 0; i < this->m_EmpNum; ++i) {
                if (this->m_EmpArray[i]->m_Name == name){
                    cout << "查找成功，职工编号为："
                         << m_EmpArray[i]->m_Id
                         <<" 号的信息如下 ： "<<endl;

                    flag = true;

                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false){
                //查找失败
                cout << "查无此人" << endl;
            }
        }
        system("pause");
        system("cls");
    }
}