#include <iostream>
#include <vector>
#include <unordered_map>

class Server {
private:
    std::string name;
    std::unordered_map<std::string, int> executionCosts;
    int load;

public:
    Server(std::string name) : name(name), load(0) {}

    std::string getName() {
        return name;
    }

    int getLoad() {
        return load;
    }

    void increaseLoad() {
        load++;
    }

    void decreaseLoad() {
        load--;
    }

    void setExecutionCost(std::string task, int cost) {
        executionCosts[task] = cost;
    }

    int getExecutionCost(std::string task) {
        if (executionCosts.find(task) != executionCosts.end()) {
            return executionCosts[task];
        }
        return 0; // Default to 0 if task not found
    }
};

class LoadBalancer {
private:
    std::vector<Server*> servers;
    int currentIndex;

public:
    LoadBalancer(std::vector<Server*> servers) : servers(servers), currentIndex(0) {}

    Server* getNextServer() {
        Server* nextServer = servers[currentIndex];
        currentIndex = (currentIndex + 1) % servers.size();
        return nextServer;
    }
};

int main() {
    const int COMMUNICATION_COST_PER_REQUEST = 2;

    // Create servers
    std::vector<Server*> servers;
    Server* server1 = new Server("Server 1");
    Server* server2 = new Server("Server 2");
    Server* server3 = new Server("Server 3");

    // Define execution costs for tasks on each server
    server1->setExecutionCost("Task A", 5);
    server1->setExecutionCost("Task B", 7);

    server2->setExecutionCost("Task A", 6);
    server2->setExecutionCost("Task B", 8);

    server3->setExecutionCost("Task A", 4);
    server3->setExecutionCost("Task B", 6);

    servers.push_back(server1);
    servers.push_back(server2);
    servers.push_back(server3);

    LoadBalancer loadBalancer(servers);

    int totalExecutionCost = 0;
    int totalCommunicationCost = 0;

    // Simulate requests
    std::vector<std::string> tasks = {"Task A", "Task B"};
    for (int i = 0; i < 10; i++) {
        std::string task = tasks[i % tasks.size()]; // Rotate through tasks
        Server* server = loadBalancer.getNextServer();
        server->increaseLoad();

        int executionCost = server->getExecutionCost(task);
        totalExecutionCost += executionCost;

        totalCommunicationCost += COMMUNICATION_COST_PER_REQUEST;
        std::cout << "Request " << i << " (Task: " << task << ") handled by " << server->getName() <<
                " (Execution Cost: $" << executionCost << ")" << std::endl;
    }

    // Print server loads
    for (Server* server : servers) {
        std::cout << server->getName() << " load: " << server->getLoad() << std::endl;
    }

    // Calculate total cost
    int totalCost = totalExecutionCost + totalCommunicationCost;
    std::cout << "Total Execution Cost: $" << totalExecutionCost << std::endl;
    std::cout << "Total Communication Cost: $" << totalCommunicationCost << std::endl;
    std::cout << "Total Cost: $" << totalCost << std::endl;

    // Free allocated memory
    for (Server* server : servers) {
        delete server;
    }

    return 0;
}
