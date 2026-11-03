#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

class Storage{
    private:
        std::vector<std::string> Todo;
    public:
        void storageToDo(std::string& s){
            Todo.push_back(s);
        }

        const std::vector<std::string> getToDos() const{
            return Todo;
        }
};

int main()
{
    Storage storage;
    std::string s;
    std::string choice;
    while(true){
    

        std::cout << "1 Add a to-do item" << std::endl;
        std::cout << "2 Check list" << std::endl;
        std::cout << "0 Exit" << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::cout << "Please enter your choice: " << std::endl;
    
        

        if(!std::getline(std::cin, choice)){
            return 0;
        }

        const auto first = choice.find_first_not_of(" \t");
    
        if(first == std::string::npos){
            std::cout << "Invalid input" << std::endl;
            continue;
        }

        const auto last = choice.find_last_not_of(" \t");
        choice = choice.substr(first, last - first + 1);

        if(choice != "0" && choice != "1" && choice != "2"){
            std::cout << "Invalide input" << std::endl;
            continue;
        }
    
        int n = choice[0] - '0';
    
        switch(n){
            case 1: {
                std::cout << "Please enter your to-do item" << std::endl;
                    if(!std::getline(std::cin, s)){
                        return 0;
                    }

                    const auto first = s.find_first_not_of(" \t");
                    if(first == std::string::npos){
                        std::cout << "The to-do list shouldn't be empty" << std::endl;
                        continue;
                    }

                    const auto last = s.find_last_not_of(" \t");
                    s = s.substr(first, last - first + 1);
                    
                    storage.storageToDo(s);
                    std::cout << "Added successfully" << std::endl;
                    std::cout << std::endl;
                    break;
            }
            case 2: {
                    const auto& todos = storage.getToDos();
                    if(todos.empty()){
                    std::cout << "The list is emtpy" << std::endl;
                }
                else{
                    for(std::size_t i = 0; i < todos.size(); i++){
                    std::cout << i + 1 << "." << todos[i] << std::endl;
                }
                    std::cout << std::endl;
                }
                break;
            }
            case 0: std::cout << "Goodbye" << std::endl;
                    return 0;
            default: std::cout << "Invalid input" << std::endl;
        }
    }

return 0;
}