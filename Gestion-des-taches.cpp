#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Définition de la classe Task
class Task {
private:
    string name;
    string description;
    bool completed;
    string priority; // Nouveau champ pour la priorité de la tâche

public:
    // Constructeur
    Task(const string &name, const string &description) : name(name), description(description), completed(false) {}

    // Méthode pour marquer la tâche comme terminée
    void completeTask() {
        completed = true;
    }

    // Méthode pour obtenir le nom de la tâche
    string getName() const {
        return name;
    }

    // Méthode pour obtenir la description de la tâche
    string getDescription() const {
        return description;
    }

    // Méthode pour obtenir le statut de complétion de la tâche
    bool isCompleted() const {
        return completed;
    }

    // Méthode pour définir la priorité de la tâche
    void setPriority(const string &p) {
        priority = p;
    }

    // Méthode pour obtenir la priorité de la tâche
    string getPriority() const {
        return priority;
    }
};

// Classe pour la gestion des tâches
class TaskManager {
private:
    vector<Task> tasks;

public:
    // Méthode pour ajouter une tâche
    void addTask(const string &name, const string &description) {
        Task newTask(name, description);
        tasks.push_back(newTask);
    }

    // Méthode pour afficher toutes les tâches
    void displayTasks() const {
        for (size_t i = 0; i < tasks.size(); ++i) {
            const Task &task = tasks[i];
            cout << "   -- Tache " << i + 1 << ":" << endl;
            cout << "Nom : " << task.getName() << endl;
            cout << "Description : " << task.getDescription() << endl;
            cout << "Statut : " << (task.isCompleted() ? "Terminée" : "Non terminée") << endl;
            cout << "Priorite : " << task.getPriority() << endl;
            cout << "-----------------------" << endl;
        }
    }

    // Méthode pour marquer une tâche comme complétée 
    void completeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completeTask();
            cout << " Tache marquee  comme completee. " << endl;
        } else {
            cout << "Indice de tache invalide." << endl;
        }
    }

    // Méthode pour supprimer une tâche
    void deleteTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Tache supprimee." << endl;
        } else {
            cout << "Indice de tache invalide." << endl;
        }
    }

    // Méthode pour attribuer une priorité à une tâche
    void assignPriority(size_t index, const string &priority) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].setPriority(priority);
            cout << "Priorite attribuee a la tache." << endl;
        } else {
            cout << "Indice de tache invalide." << endl;
        }
    }

    // Méthode pour rechercher une tâche par son nom
    void searchTaskByName(const string &name) const {
        bool found = false;
        for (const Task &task : tasks) {
            if (task.getName() == name) {
                cout << "Tache trouvee :" << endl;
                cout << "Nom : " << task.getName() << endl;
                cout << "Description : " << task.getDescription() << endl;
                cout << "Statut : " << (task.isCompleted() ? "Terminee" : "Non terminee") << endl;
                cout << "Priorite : " << task.getPriority() << endl;
                cout << "-----------------------" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Aucune tache correspondante trouvee." << endl;
        }
    }
};


int main() {
    TaskManager taskManager;
    char choice;

    do {
        cout << "                                    " << endl ;
        cout << "        ******* Menu ******* " << endl;
        cout << "    1. pour Ajouter une nouvelle tache. " << endl;
        cout << "    2. Pour Afficher la liste des taches." << endl;
        cout << "    3. Pour Marquer une tache comme completee." << endl;
        cout << "    4. Pour Supprimer une tache. " << endl;
        cout << "    5. Pour Attribuer une priorite e une tache." << endl;
        cout << "    6. Pour Rechercher une tache par son nom." << endl;
        cout << "    7.  sortir." << endl;
        cout << "     ------------------------------ " << endl;
        cout << "                                    " << endl ;
        cout << " -- merci de saisir votre choix -- " << endl ;
        cout << "Choix : ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1': {
                string name , description ;
                cout << "Nom de la nouvelle tache : ";
                getline(cin, name);
                cout << "Description de la tache : ";
                getline(cin, description);
                taskManager.addTask(name, description);
                 cout << " la tache a ete ajoutee avec succes ";
                 cout << "                                    " << endl ;
                break;
            }
            case '2':
                cout << "        ******* Liste des taches  ******* " << endl;
                taskManager.displayTasks();
                cout << "                                    " << endl ;
                break;
            case '3': {
                size_t index;
                cout << "Indice de la tache a marquer comme completee : ";
                cin >> index;
                taskManager.completeTask(index);
                cout << "                                    " << endl ;
                break;
            }
            case '4': {
                size_t index;
                cout << "Indice de la tache a supprimer : ";
                cin >> index;
            
                    taskManager.deleteTask(index);
                    cout << "                                    " << endl ;
                    break;
            }
            case '5': {
                size_t index;
                string priority;
                cout << "Indice de la tache a laquelle attribuer une priorite : ";
                cin >> index;
                cout << "Priorite (faible/moyenne/elevee) : ";
                cin >> priority;
                taskManager.assignPriority(index, priority);
                cout << "                                    " << endl ;
                break;
            }
            case '6': {
                string name;
                cout << "Nom de la tache a rechercher : ";
                cin.ignore();
                getline(cin, name);
                taskManager.searchTaskByName(name);
                cout << "                                    " << endl ;
                break;
            }
            case '7':
                cout << " Merci d'utulise notre gestionaire de taches . A bientot !! " << endl;
                cout << "                                    " << endl ;
                break;
            default:
                cout << "votre choix n'existe pas !! " << endl;
                cout << " veuillez ressayer.  " << endl ;
                cout << "                                    " << endl ;
        }
    } while (choice != '7');

    return 0;
}
