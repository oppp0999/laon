#include <iostream>

//작업자 인터페이스
class Worker{
    public:
        virtual void doWork() = 0;
};

//작업자 클래스
class GeneralWorker : public Worker {
    public:
        void doWork() override {
            std::cout << "General worker performs general tasks." << std::endl;
        }
};

// 관리자 인터페이스
class Manager {
public:
    virtual void manage() = 0;
};

// 관리자 클래스
class AdminManager : public Manager {
public:
    void manage() override {
        std::cout << "Admin manager performs administrative tasks." << std::endl;
    }
};

class Client{
    private:
        Worker* worker;
        Manager* manager;

    public:
        Client(Worker* w, Manager* m) : worker(w), manager(m){}

    void executeTasks(){
        worker->doWork();
    }

    void executeManagement(){
        manager->manage();
    }
};

int main(){
    GeneralWorker generalWorker;
    AdminManager adminManager;

    Client client1(&generalWorker, & adminManager);
    client1.executeTasks();
    client1.executeManagement();

    return 0;
}