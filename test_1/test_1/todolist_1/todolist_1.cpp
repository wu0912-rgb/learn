#include <vector>
#include <iostream>
#include<string>
using namespace std;




int main()
{
    void addTask(vector<string>&tasks);
    void printMenu();
    void deleteTask(std::vector<std::string>&tasks);
    void viewTasks(vector<string>&tasks);
    vector<string>tasks;
    int choice = 0;
    cout << "===简易待办事项列表===" << endl;
    do {
        printMenu();
        cin >> choice;
        // 清除输入缓冲区，防止后续getline读取到换行符
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice){
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            deleteTask(tasks);
            break;
        case 4:
            cout << "感谢使用待办事项列表,再见" << endl;
            break;
        default:
            cout << "无效选择，请重试！" << endl;
        }
    } while (choice != 4);
    return 0;
}
void printMenu() {
    cout << "\n--- 主菜单 ---" << endl;
    cout << "1. 添加任务" << endl;
    cout << "2. 查看所有任务" << endl;
    cout << "3. 删除任务" << endl;
    std::cout << "4. 文件操作" << std::endl;  // 新增：文件操作菜单
    std::cout << "5. 退出程序" << std::endl;
    std::cout << "请选择操作 (1-5): ";
}
void addTask(vector<string>& tasks){
    string task;
    cout<< "请输入新任务" << endl;
    getline(cin, task);
    if (!task.empty()) {
        tasks.push_back(task);
        cout << "任务添加成功" << endl;
    }
    else {
        cout << "任务不能为空" << endl;
    }
}
void viewTasks(vector<string>& tasks) {
    if (tasks.empty())
    {
        cout << "没有待办任务" << endl;
    }
    else {
        for (string task : tasks)
        {
            int i = 1;
            cout << i << "." << task << endl;
            i++;
        }
        cout << "总计:" << tasks.size() << "项任务" << endl;
    }
}
// 删除任务
void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "当前没有可删除的任务。" << std::endl;
        return;
    }

    viewTasks(tasks); // 先显示所有任务

    int taskNumber;
    std::cout << "请输入要删除的任务编号: ";
    std::cin >> taskNumber;

    // 检查输入是否为数字且有效
    if (std::cin.fail()) {
        std::cin.clear(); // 清除错误状态
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "请输入有效的数字！" << std::endl;
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清除缓冲区

    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        std::string removedTask = tasks[taskNumber - 1];
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "任务 \"" << removedTask << "\" 已删除！" << std::endl;
    }
    else {
        std::cout << "无效的任务编号！" << std::endl;
    }
}
