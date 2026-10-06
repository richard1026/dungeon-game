#include "Dungeon.h"
void Dungeon::createPlayer()
{
    cout << "Please enter your name" << endl;
    string name;
    cin >> name;
    player = Player(name, 2000, 500, 500,100,100,0);
    cout << "What type do you want to have? Fire, water, or grass?" << endl;
    string type;
    cin >> type;
    player.settype(type);
    cout << "Welcome to Dungeon, " << name << "!!!" << endl;
    player.triggerEvent(&player);
}
Dungeon::Dungeon() {

}
void Dungeon::createMap()
{
    Monster* ghidorah = new Monster("Ghidorah", 1200, 600, 600,"fire");
    Monster* godzila = new Monster("Godzilla", 1000, 500, 500,"water");
    Monster* kong = new Monster("Kong", 1000, 500, 500,"grass");
    Monster* mothra = new Monster("Mothra", 800, 400, 400, "fire");
    Monster* rodan = new Monster("Rodan", 700, 350, 350, "water");
    Monster* behemoth = new Monster("Beheoth", 700, 350, 350, "grass");
    Monster* scylla = new Monster("Scylla", 600, 300, 300, "fire");
    Monster* methuselah = new Monster("Methuselah", 600, 300, 300, "water");
    Monster* muto = new Monster("MUTO", 600, 300, 300, "grass");

    Item* protein = new Item("protein", 100, 0, 0, 0, 0, 0);
    Item* creatine = new Item("creatine", 150, 0, 0, 0, 0, 0);
    Item* starch = new Item("starch", 175, 0, 0, 0, 0, 0);
    Item* fat = new Item("fat", 200, 0, 0, 0, 0, 0);
    Item* water = new Item("water", 0, 0, 0, 0, 10, 0);
    Item* juice = new Item("juice", 0, 0, 0, 0, 15, 0);
    Item* coke = new Item("coke", 0, 0, 0, 0, 20, 0);
    Item* pistol = new Item("pistol", 0, 50, 0, 0, 0, 0);
    Item* shotgun = new Item("shotgun", 0, 55, 0, 0, 0, 0);
    Item* submachine_gun = new Item("submachineGun", 0, 60, 0, 0, 0, 0);
    Item* rifle = new Item("rifle", 0, 65, 0, 0, 0, 0);
    Item* sniper_riflen = new Item("sniperRifle", 0, 70, 0, 0, 0, 0);
    Item* machine_gun = new Item("machineGun", 0, 75, 0, 0, 0, 0);
    Item* milk = new Item("milk", 0, 0, 0, 0, 0, -3);
    Item* yogurt = new Item("yogurt", 0, 0, 0, 0, 0, -3);
    Item* ice_cream = new Item("iceCream", 0, 0, 0, 0, 0, -4);
    Item* sheild = new Item("sheild", 0, 0, 50, 0, 0, 0);
    Item* bulletproof_vest = new Item("bulletproofVest", 0, 0, 100, 0, 0, 0);
    Item* pizza = new Item("pizza", 0, 0, 0, 10, 0, 0);
    Item* sandwich = new Item("sandwich", 0, 0, 0, 15, 0, 0);
    Item* donut = new Item("donut", 0, 0, 0, 20, 0, 0);
    vector<Item*>obj1{ shotgun,protein,pizza };
    vector<Item*>obj2{ submachine_gun,water,bulletproof_vest };
    vector<Item*>obj3{ rifle,creatine,ice_cream };
    vector<Item*>obj4{ machine_gun,juice,sandwich };
    vector<Item*>obj5{ sniper_riflen,starch,yogurt };
    vector<Item*>obj6{ pistol,coke,milk };
    vector<Item*>obj7{ sheild,fat,donut };


    

    NPC* Dr_Mark = new NPC("Dr. Mark Russell", "Monster can't live with people, we need to kill them all. Let me help you!!!", obj1);
    NPC* Dr_Emma = new NPC("Dr. Emma Russell", "You need to be careful with Ghidorah. He is the king of monster. Let me give you something to become stronger.", obj2);
    NPC* Madison = new NPC("Madison", "You look so tired, how can I help you?", obj3);
    NPC* Dr_Rick = new NPC("Dr. Rick Stanton", "The remaining half is more difficult. You need more weapons ",obj4);
    NPC* Dr_Sam = new NPC("DR. Sam Coleman", "We believe you can save the people. Let me help you.", obj5);
    NPC* Dr_Vivienne = new NPC("Dr. VIvienne Graham", "Muto is strong to beat. You must need some supply", obj6);
    NPC* Dr_Ishiro = new NPC("Dr. Ichiro Serizawa", "You almost arrive the exit. Let me give you a helping hand", obj7);

    Room* Monarch0 = new Room(false, 0," ", vector<Object*>{});
    Room* Monarch1 = new Room(false, 1, "Desert",vector<Object*>{Dr_Mark});
    Room* Monarch2 = new Room(false, 2, "Forest",vector<Object*>{godzila, Dr_Emma});
    Room* Monarch3 = new Room(false, 3, "Swamp",vector<Object*>{methuselah});
    Room* Monarch4 = new Room(false, 4, "Desert", vector<Object*>{kong});
    Room* Monarch5 = new Room(false, 5, "Forest", vector<Object*>{mothra});
    Room* Monarch6 = new Room(false, 6, "Swamp", vector<Object*>{rodan});
    Room* Monarch7 = new Room(false, 7, "Desert", vector<Object*>{Madison});
    Room* Monarch8 = new Room(false, 8, "Forest", vector<Object*>{behemoth});
    Room* Monarch9 = new Room(false, 9, "Swamp", vector<Object*>{Dr_Sam});
    Room* Monarch10 = new Room(false, 10, "Desert", vector<Object*>{scylla});
    Room* Monarch11 = new Room(false, 11, "Forest", vector<Object*>{Dr_Rick});
    Room* Monarch12 = new Room(false, 12, "Swamp", vector<Object*>{Dr_Vivienne});
    Room* Monarch13 = new Room(false, 13, "Desert", vector<Object*>{muto });
    Room* Monarch14 = new Room(false, 14, "Forest", vector<Object*>{ Dr_Ishiro});
    Room* Monarch15 = new Room(true, 15, "Swamp", vector<Object*>{ghidorah});

    rooms.push_back(Monarch0);
    rooms.push_back(Monarch1);
    rooms.push_back(Monarch2);
    rooms.push_back(Monarch3);
    rooms.push_back(Monarch4);
    rooms.push_back(Monarch5);
    rooms.push_back(Monarch6);
    rooms.push_back(Monarch7);
    rooms.push_back(Monarch8);
    rooms.push_back(Monarch9);
    rooms.push_back(Monarch10);
    rooms.push_back(Monarch11);
    rooms.push_back(Monarch12);
    rooms.push_back(Monarch13);
    rooms.push_back(Monarch14);
    rooms.push_back(Monarch15);

    player.setCurrentRoom(Monarch0);
    Monarch0->setRightRoom(Monarch1);
    Monarch0->setUpRoom(Monarch9);
    Monarch1->setUpRoom(Monarch2);
    Monarch1->setDownRoom(Monarch3);
    Monarch1->setRightRoom(Monarch5);
    Monarch1->setLeftRoom(Monarch0);
    Monarch2->setUpRoom(Monarch6);
    Monarch2->setDownRoom(Monarch3);
    Monarch2->setRightRoom(Monarch10);
    Monarch3->setUpRoom(Monarch1);
    Monarch3->setRightRoom(Monarch4);
    Monarch4->setUpRoom(Monarch7);
    Monarch4->setLeftRoom(Monarch3);
    Monarch4->setRightRoom(Monarch14);
    Monarch5->setLeftRoom(Monarch1);
    Monarch5->setRightRoom(Monarch7);
    Monarch6->setDownRoom(Monarch2);
    Monarch6->setLeftRoom(Monarch9);
    Monarch7->setUpRoom(Monarch11);
    Monarch7->setDownRoom(Monarch4);
    Monarch7->setLeftRoom(Monarch5);
    Monarch7->setRightRoom(Monarch8);
    Monarch8->setRightRoom(Monarch13);
    Monarch8->setLeftRoom(Monarch7);
    Monarch9->setDownRoom(Monarch0);
    Monarch9->setRightRoom(Monarch6);
    Monarch10->setRightRoom(Monarch11);
    Monarch10->setLeftRoom(Monarch2);
    Monarch11->setLeftRoom(Monarch10);
    Monarch11->setRightRoom(Monarch12);
    Monarch12->setDownRoom(Monarch15);
    Monarch12->setLeftRoom(Monarch11);
    Monarch13->setDownRoom(Monarch14);
    Monarch13->setLeftRoom(Monarch8);
    Monarch14->setUpRoom(Monarch13);
    Monarch14->setLeftRoom(Monarch4);
    Monarch14->setRightRoom(Monarch15);
    Monarch15->setUpRoom(Monarch12);
    Monarch15->setLeftRoom(Monarch14);

}

void Dungeon::handleMovement()
{
    cout << "What's your next move?" << endl;

    if (player.getCurrentRoom()->getIsExit())
        cout << "Press [e] to exit." << endl;
    if (player.getCurrentRoom()->getRightRoom() != nullptr)
        cout << "Press [r] to go right" << endl;
    if (player.getCurrentRoom()->getLeftRoom() != nullptr)
        cout << "Press [l] tp go left" << endl;
    if (player.getCurrentRoom()->getUpRoom() != nullptr)
        cout << "Press [u] to go up" << endl;
    if (player.getCurrentRoom()->getDownRoom() != nullptr)
        cout << "Press [d] to go down." << endl;

    char choice;
    cin >> choice;
    if ((choice == 'e' || choice == 'E')&& player.getCurrentRoom()->getIsExit())
    {
        cout << "congratulations, you are the winner!!!" << endl;
        exit(0);
    }
    else if ((choice == 'R' || choice == 'r')&& player.getCurrentRoom()->getRightRoom() != nullptr)
    {
        player.changeRoom(player.getCurrentRoom()->getRightRoom());
    }
    else if ((choice == 'l' || choice == 'L')&& player.getCurrentRoom()->getLeftRoom() != nullptr)
    {
        player.changeRoom(player.getCurrentRoom()->getLeftRoom());
    }
    else if ((choice == 'u' || choice == 'U')&& player.getCurrentRoom()->getUpRoom() != nullptr)
    {
        player.changeRoom(player.getCurrentRoom()->getUpRoom());
    }
    else if ((choice == 'd' || choice == 'D')&& player.getCurrentRoom()->getDownRoom() != nullptr)
    {
        player.changeRoom(player.getCurrentRoom()->getDownRoom());
    }
    
    else
        cout << "Invalid operation. Please try again" << endl;
}
void Dungeon::handleEvent(Object* obj)
{
    obj->triggerEvent(&player);
    return;
}
void Dungeon::chooseAction(vector<Object*> obj)
{
    for (auto i : obj)
    {
        handleEvent(i);
        player.getCurrentRoom()->popObject(i);
    }
    obj.clear();
    while (obj.size() > 0)
        obj.pop_back();
    cout << "What's you're next action?" << endl;
    char action;
    cout << "Press [m] to move" << endl;
    cout << "Press [s] to show status." << endl;
    cout << "Press [q] to quit." << endl;
    cout << "Press [h] to show hunger." << endl;
    cout << "Press [l] to list inventory." << endl;
    cin >> action;
    if (action == 'm' || action == 'M')
    {
        handleMovement();
    }
    else if (action == 's' || action == 'S')
    {
        player.triggerEvent(&player);
    }
    else if (action == 'q' || action == 'Q')
    {
        exit(0);
    }
    else if (action == 'h' || action == 'H') {
        cout << player.getName() << "'s hunger: " << player.gethunger() << ", thurst: " << player.getthurst() << ", poison: " << player.getpoison() << endl;
    }
    else if (action == 'l' || action == 'L') {
        player.listinventory();
    }
    else
        cout << "Invalid Operation. Please try again." << endl;
}
void Dungeon::hunger() {
    int i;
    int j = rand() % 5;
    if (rand() % 2 == 1)
        i = 2;
    else
        i = 1;
    if (player.getCurrentRoom()->getenvironment() == "Desert") {
        if (i == 2)
            cout << "You encoutered sand storm, thurst and hunger decrease dramatically" << endl;
        if (player.gethunger() > 0) {
            player.sethunger(player.gethunger() - i * 3*(player.getpoison()+1));
            cout << "state decreases: hunger - " << i * 3 * (player.getpoison() + 1) << endl;
        }
        else 
        {
            player.setCurrentHealth(player.getCurrentHealth() - i * 3 * (player.getpoison() + 1));
            cout << "state decreases: current health - " << i * 3 * (player.getpoison() + 1) << endl;
        }
        if (player.getthurst() > 0) {
            player.setthurst(player.getthurst() - i * 6 * (player.getpoison() + 1));
            cout << "state decreases: thurst - " << i * 6 * (player.getpoison() + 1) << endl;
        }
        else
        {
            player.setCurrentHealth(player.getCurrentHealth() - i * 6 * (player.getpoison() + 1));
            cout << "state decreases: current health - " << i * 6 * (player.getpoison() + 1) << endl;
        }
        if (j==2||j==4) {
            cout << "You find an oasis" << endl;
            cout << "state increases: hunger + 6" << endl << "state increases: thurst + 12" << endl;
            player.sethunger(player.gethunger() + 6);
            player.setthurst(player.getthurst() + 12);
        }
    }
    if (player.getCurrentRoom()->getenvironment() == "Forest") {
        if (i == 2)
            cout << "You encoutered wild fire, thurst and hunger decrease dramatically" << endl;
        if (player.gethunger() > 0) {
            player.sethunger(player.gethunger() - i * 6 * (player.getpoison() + 1));
            cout << "state decreases: hunger - " << i * 6 * (player.getpoison() + 1) << endl;
        }
        else
        {
            player.setCurrentHealth(player.getCurrentHealth() - i * 6 * (player.getpoison() + 1));
            cout << "state decreases: current health - " << i * 6 * (player.getpoison() + 1) << endl;
        }
        if (player.getthurst() > 0) {
            player.setthurst(player.getthurst() - i * 3 * (player.getpoison() + 1));
            cout << "state decreases: thurst - " << i * 3 * (player.getpoison() + 1) << endl;
        }
        else
        {
            player.setCurrentHealth(player.getCurrentHealth() - i * 3 * (player.getpoison() + 1));
            cout << "state decreases: current health - " << i * 3 * (player.getpoison() + 1) << endl;
        }
        if (j == 2 || j == 4) {
            cout << "You find a lake" << endl;
            cout << "state increases: hunger + 12" << endl << "state increases: thurst + 6" << endl;
            player.sethunger(player.gethunger() + 12);
            player.setthurst(player.getthurst() + 6);
        }
    }
    if (player.getCurrentRoom()->getenvironment() == "Swamp") {
        if (i == 2)
        {
            cout << "Snakes come in great amount, you are poisoned by snakes venom seriously." << endl;
            cout << "state increases: poison + 2" << endl;
            player.setpoison(player.getpoison() + 2);
        }
        else {
            cout << "You are poisoned by sake venom" << endl;
            cout << "state increases: poison + 1" << endl;
            player.setpoison(player.getpoison() + 1);
        }
        if (player.gethunger() > 0) {
            player.sethunger(player.gethunger() - i * 3 * (player.getpoison() + 1));
            cout << "state decreases: hunger - " << i * 3 * (player.getpoison() + 1) << endl;
        }
        else
        {
            player.setCurrentHealth(player.getCurrentHealth() - i * 3 * (player.getpoison() + 1));
            cout << "state decreases: current health - " << i * 3 * (player.getpoison() + 1) << endl;
        }
        if (player.getthurst() > 0) {
            player.setthurst(player.getthurst() - i * 3 * (player.getpoison() + 1));
            cout << "state decreases: thurst - " << i * 3 * (player.getpoison() + 1) << endl;
        }
        else
        {
            player.setCurrentHealth(player.getCurrentHealth() - i * 3 * (player.getpoison() + 1));
            cout << "state decreases: current health - " << i * 3 * (player.getpoison() + 1) << endl;
        }
        if (j == 2 || j == 4) {
            cout << "You find a bottle of milk" << endl;
            cout << "state decreases: poison - 2"<< endl;
            if ((player.getpoison() - 2) > 0)
                player.setpoison(player.getpoison() - 2);
            else player.setpoison(1);
        }
    }

}
void Dungeon::startGame()
{
    createPlayer();
    createMap();
}
bool Dungeon::checkGameLogic()
{
    if (player.getCurrentRoom() == nullptr || player.getCurrentHealth() <= 0)
        return false;
    else
        return true;
}
void Dungeon::runDungeon() {
    startGame();
    while (checkGameLogic())
    {   
        if (rand() % 6 == 0) {
            cout << "You are injured accidently" << endl;
            cout << "Status decreases: current health - 100" << endl;
            player.setCurrentHealth(player.getCurrentHealth() - 100);
        }
        chooseAction(player.getCurrentRoom()->getObjects());
        hunger();
        system("pause");
    }
    exit(0);
}