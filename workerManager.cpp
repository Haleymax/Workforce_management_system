//
// Created by huang on 2024/6/6.
//

#include "Headers/workerManager.h"
#include "Headers/worker.h"
#include "Headers/employee.h"



int main(){

    //测试案例
    Worker * worker = NULL;
    worker = new Employee(1, "Haley", 1);
    worker->showInfo();

    //实例化管理者对象
    WorkerManager w;

    int choice = 0;  //用于存储用户的选项

    while (true){
        w.Show_Menu();
        cout << "请输入您的选择 :" <<endl;
        cin >> choice;  //接受用户的选项

        switch (choice) {
            case 0:     //退出系统
                w.ExitSystem();
                break;
            case 1:     //增加员工
                break;
            case 2:     //显示职工
                break;
            case 3:     //删除职工
                break;
            case 4:     //修改职工
                break;
            case 5:     //查找职工
                break;
            case 6:     //排序职工
                break;
            case 7:     //清空文档
                break;
            default:
                system("cls");
                break;
        }
    }



}

//退出系统
void WorkerManager::ExitSystem() {
    cout << "欢迎下次使用" <<endl;
    system("pause");
    exit(0);
}