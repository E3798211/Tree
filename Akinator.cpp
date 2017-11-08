#include "Akinator.h"

int Akinator::Align(FILE* output, int depth)
{
    assert(output != nullptr);
    for(int i = 0; i < depth; i++)
        fprintf(output, "\t");

    return depth;
}

char* Akinator::FileRead(FILE* input)
{
    EnterFunction();
    PrintVar(input);

    assert(input != nullptr);

    if(fseek(input, 0, SEEK_END)){
        SetColor(RED);
        DEBUG printf("=====   Cannot set last position in file   =====\n");
        SetColor(DEFAULT);

        QuitFunction();
        return nullptr;
    }

    int file_size = ftell(input);
    PrintVar(file_size);

    if(file_size == EOF){
        SetColor(RED);
        DEBUG printf("=====   Cannot get pointer's position in   =====\n");
        SetColor(DEFAULT);

        QuitFunction();
        return nullptr;
    }

    char* data = nullptr;
    try{
        data = new char [file_size + 1];
    }
    catch(const std::bad_alloc& ex){
        SetColor(RED);
        DEBUG printf("=====   Cannot allocate %d bytes   =====\n", file_size + 1);
        SetColor(DEFAULT);

        QuitFunction();
        return nullptr;
    }

    rewind(input);
    fread(data, 1, file_size, input);
    data[file_size] = '\0';

    PrintVar(input);

    QuitFunction();
    return data;
}

int Akinator::AppendNode(char* data, int* place_in_data, Node* app_node)
{
    EnterFunction();

    while(data[(*place_in_data)] != '(')    (*place_in_data)++;
    while(data[(*place_in_data)] != '"')    (*place_in_data)++;

    int node_data_beg = ++(*place_in_data);
    int node_data_end = node_data_beg;
    while(data[node_data_end] != '"')       node_data_end++;

    PrintVar(node_data_end);
    PrintVar(node_data_end - node_data_beg);


    char* node_text = nullptr;
    try
    {
        node_text = new char [node_data_end - node_data_beg + 1];
    }
    catch(const std::bad_alloc& ex)
    {
        SetColor(RED);
        DEBUG printf("=====   Cannot allocate %d bytes for new node   =====\n", node_data_end - node_data_beg + 1);
        SetColor(DEFAULT);

        QuitFunction();
        return NODE_NOT_CREATED;
    }

    int i = 0;
    while((*place_in_data) != node_data_end)
        node_text[i++] = data[(*place_in_data)++];

    node_text[node_data_end - node_data_beg] = '\0';
    PrintVar(node_text);
    PrintVar(*place_in_data);

    tree.SetData(app_node, node_text);

    bool left_added = false;
    Node* tmp;

    while(data[(*place_in_data)] != ')'){
        if(data[(*place_in_data)] == '('){
            if(!left_added){
                tree.AddLeft (app_node, &tmp);
                AppendNode(data, place_in_data, app_node->Left);

                left_added = true;

            }else{
                tree.AddRight(app_node, &tmp);
                AppendNode(data, place_in_data, app_node->Right);
            }
        }
        (*place_in_data)++;
    }

    PrintVar(*place_in_data);

    delete [] node_text;
    node_text = nullptr;

    QuitFunction();
    return OK;
}

int Akinator::LoadData(const char* filename)
{
    EnterFunction();

    assert(filename != nullptr);

    FILE* database = fopen(filename, "r");
    if(database == nullptr){
        SetColor(RED);
        DEBUG printf("=====   Cannot open file %s   =====\n", filename);
        SetColor(DEFAULT);

        return FILE_NOT_OPENED;
    }

    char* data = FileRead(database);
    PrintVar(data);

    int cur_pos_in_data = 0;        // Counter for AppendNode()
    AppendNode(data, &cur_pos_in_data, tree.GetRoot());

    fclose(database);

    QuitFunction();
    return OK;
}

int Akinator::PrintBranch(FILE* output, Node* root_node, int recursion_depth)
{
    EnterFunction();

    assert(output != nullptr);
    assert(root_node != nullptr);

    Align(output, recursion_depth);
    fprintf(output, "(\"");
    fprintf(output, "%s", root_node->Data);
    fprintf(output, "\"\n");

    PrintVar(root_node->Data);

    if(root_node->Left != nullptr)
        PrintBranch(output, root_node->Left, recursion_depth + 1);
    if(root_node->Right != nullptr)
        PrintBranch(output, root_node->Right, recursion_depth + 1);

    Align(output, recursion_depth);
    fprintf(output, ")\n");

    QuitFunction();

    return OK;
}

int Akinator::UnloadData(const char* filename)
{
    EnterFunction();

    assert(filename != nullptr);

    FILE* output = fopen(filename, "w");
    if(output == nullptr){
        SetColor(RED);
        DEBUG printf("=====   Cannot open file %s   =====\n", filename);
        SetColor(DEFAULT);

        return FILE_NOT_OPENED;
    }

    PrintBranch(output, tree.GetRoot());

    fclose(output);

    QuitFunction();
    return OK;
}

bool Akinator::UserAnswer(const char* question)
{
    EnterFunction();

    assert(question != nullptr);

    printf("%s?\nYour answer: ", question);

    char ans[100] = "";

    bool choise = false;
    while(1){
        while(!scanf("%s", &ans)){
            printf("I do not understand you...\nPlease, say YES or NO: ");
            getchar();
        }

        if      (!strcmp(ans, "YES") || !strcmp(ans, "Y")){
            choise = true;
            break;
        }else if(!strcmp(ans, "NO")  || !strcmp(ans, "N")){
            choise = false;
            break;
        }

        printf("I do not understand you...\nPlease, say YES or NO: ");
    }

    PrintVar(ans);
    PrintVar(choise);
    QuitFunction();

    return choise;
}

int Akinator::AskAboutNewName(char* user_answer)
{
    printf("What have you guessed?\nYour answer: ");
    getchar();
    fgets(user_answer, 100, stdin);
    // Deleting \n
    user_answer[strlen(user_answer) - 1] = '\0';

    return OK;
}

int Akinator::AskAboutNewDiff(const char* old_answer, const char* new_answer, char* user_answer)
{
    printf("What is the difference between \"%s\" and \"%s\"?\nYour answer: ", new_answer, old_answer);
    fgets(user_answer, 100, stdin);
    // Deleting \n
    user_answer[strlen(user_answer) - 1] = '\0';

    return OK;
}

int Akinator::AddNewAnswer(Node* current_node, char* difference, char* new_answer)
{
    EnterFunction();

    size_t data_len = strlen(current_node->Data);

    char* old_answer = nullptr;
    try
    {
        old_answer = new char [data_len + 1];
    }
    catch(const std::bad_alloc& ex)
    {
        SetColor(RED);
        printf("=====   Cannot allocate %d bytes for old_answer   =====\n", data_len + 1);
        SetColor(DEFAULT);

        PrintVar(current_node->Data);

        QuitFunction();
        return DATA_NOT_CREATED;
    }

    strcpy(old_answer, current_node->Data);
    bool node_is_right = current_node->Is_right;
    Node* parent = current_node->Parent;

    tree.DeleteBranch(current_node);

    Node* new_root = nullptr;
    if(node_is_right)       tree.AddRight(parent, &new_root);
    else                    tree.AddLeft (parent, &new_root);

    tree.SetData(new_root, difference);

    Node* new_root_branch = nullptr;
    tree.AddRight(new_root, &new_root_branch);
    tree.SetData(new_root_branch, new_answer);

    tree.AddLeft(new_root, &new_root_branch);
    tree.SetData(new_root_branch, old_answer);

    delete [] old_answer;
    old_answer = nullptr;

    QuitFunction();
    return OK;
}

int* Akinator::BuildPath(Node* start, Node* destination)
{
    EnterFunction();

    int backtrace_reverse[tree.GetNNodes()];
    for(int i = 0; i < tree.GetNNodes(); i++)
        backtrace_reverse[i] = STOP;

    Node* current_node = destination;
    int i = 0;
    int steps = 0;
    while(current_node != start){
        if(current_node->Is_right)      backtrace_reverse[i++] = RIGHT;
        else                            backtrace_reverse[i++] = LEFT;

        steps++;
        current_node = current_node->Parent;
    }

    for(int k = 0; k < tree.GetNNodes(); k++)
        PrintVar(backtrace_reverse[k]);
    PrintVar(steps);

    // Reverting
    int* path = nullptr;
    try
    {
        path = new int [steps];
    }
    catch(const std::bad_alloc& ex)
    {
        SetColor(RED);
        DEBUG printf("=====   Cannot allocate %d int's   =====\n", steps);
        SetColor(DEFAULT);

        QuitFunction();
        return nullptr;
    }

    for(int k = 0; k < steps - 1; k++)
        path[k] = backtrace_reverse[steps - k - 1];
    path[steps - 1] = STOP;

    for(int k = 0; k < steps; k++)
        PrintVar(path[k]);

    QuitFunction();
    return path;
}

int Akinator::PrintDiff(const char* ans_1, const char* ans_2, int* path_1, int* path_2)
{
    EnterFunction();

    assert(ans_1 != nullptr);
    assert(ans_2 != nullptr);
    assert(path_1 != nullptr);
    assert(path_2 != nullptr);

    printf("%s and %s have something in common.\n", ans_1, ans_2);

    int i = 0;
    Node* current_node = tree.GetRoot();
    while(path_1[i] == path_2[i]){
        if(path_1[i] == STOP)
            break;

        printf("Both of them %s\n", current_node->Data);

        if(path_1[i] == RIGHT)          current_node = current_node->Right;
        else                            current_node = current_node->Left;

        i++;
    }
    printf("Both of them %s\n", current_node->Data);

    Node* tmp = current_node;

    printf("\nBut %s is different from %s.\n", ans_1, ans_2);

    int  counter_1 = i;
    if(path_1[counter_1] == RIGHT)        current_node = current_node->Right;
    else                                    current_node = current_node->Left;

    while(path_1[counter_1] != STOP){
        printf("%s\n", current_node->Data);

        if(path_1[counter_1] == RIGHT)      current_node = current_node->Right;
        else                                current_node = current_node->Left;

        counter_1++;
    }

    printf("\nWhile %s:\n", ans_2);

    int counter_2 = i;
    current_node = tmp;
    if(path_2[counter_2] == RIGHT)        current_node = current_node->Right;
    else                                    current_node = current_node->Left;

    while(path_2[counter_2] != STOP){
        printf("%s\n", current_node->Data);

        if(path_2[counter_2] == RIGHT)      current_node = current_node->Right;
        else                                current_node = current_node->Left;

        counter_2++;
    }

    QuitFunction();
    return OK;
}

int Akinator::CompareAnswers(const char* ans_1, const char* ans_2)
{
    EnterFunction();

    Node*  first_node = tree.FindNode(tree.GetRoot(), ans_1);
    PrintVar(first_node);
    Node* second_node = tree.FindNode(tree.GetRoot(), ans_2);
    PrintVar(second_node);

    SAFE {
    if(!tree.NodeExists(tree.GetRoot(), first_node)){
        SetColor(BLUE);
        USR_INFORM printf("ans_1 does not exist\n");
        SetColor(DEFAULT);

        return NODE_DOES_NOT_EXIST;
    }
    if(!tree.NodeExists(tree.GetRoot(), second_node)){
        SetColor(BLUE);
        USR_INFORM printf("ans_2 does not exist\n");
        SetColor(DEFAULT);

        return NODE_DOES_NOT_EXIST;
    }
    }

    PrintDiff(ans_1, ans_2, BuildPath(tree.GetRoot(), first_node), BuildPath(tree.GetRoot(), second_node));

    QuitFunction();
    return OK;
}


    Akinator::Akinator(const char* filename)
{
    EnterFunction();

    LoadData(filename? filename : DEFAULT_INPUT);

    QuitFunction();
}

    Akinator::~Akinator()
{
    EnterFunction();

    UnloadData(DEFAULT_OUTPUT);

    QuitFunction();
}

int Akinator::Action()
{
    EnterFunction();

    printf("Hello! My name is Jonny! I know everything.\nThink about something and let me guess...\n");

    Node* current_node = tree.GetRoot();
    while(!tree.IsLast(current_node)){
        if(UserAnswer(current_node->Data))      current_node = current_node->Right;
        else                                    current_node = current_node->Left;
    }

    printf("This is %s!\n", current_node->Data);
    bool user_confirmed = UserAnswer("Am I right");

    if(!user_confirmed){
        char new_name[100];
        AskAboutNewName(new_name);
        char difference[100];
        AskAboutNewDiff(current_node->Data, new_name, difference);

        AddNewAnswer(current_node, difference, new_name);
    }else
        printf("I've said...\n");

    QuitFunction();
    return OK;
}

