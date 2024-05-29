/*
 * Hướng dẫn chạy testcase
 * Chạy 2 lệnh sau trong terminal
 *
 * Lệnh 1:
 * g++ -o main main.cpp
 *
 * Lệnh 2:
 * Chạy full 200 test
 * ./main
 *
 * Chạy test chỉ định
 * ./main <test>
 * VD: ./main 111
 *
 * Chạy cụm test
 * ./main <from> <to>
 * VD: ./main 1 10
 */

#include "map.cpp"
using namespace std;

void comparefile(int start, int end)
{
    vector<int> result;
    for (int i = start; i <= end; i++)
    {
        string outputFile = "testcase/output/output" + to_string(i) + ".txt";
        string expectFile = "testcase/expect/expect" + to_string(i) + ".txt";
        ifstream read_output(outputFile);
        ifstream read_expect(expectFile);
        if (read_expect.fail())
        {
            cout << "Error reading file - " << i << endl;
            return;
        }
        string s1, s2;
        while (read_output >> s1 && read_expect >> s2)
        {
            if (s1 != s2)
            {
                result.push_back(i);
                break;
            }
        }
        if (read_output >> s1 || read_expect >> s2)
        {
            if (result.size() == 0 || result.size() > 0 && result[result.size() - 1] != i)
                result.push_back(i);
        }
    }

    if (result.size() == 0)
    {
        cout << "Success: test " << start << " to " << end << endl;
    }
    else
    {
        cout << "percent success : " << (1 - result.size() * 1.0 / (end - start + 1)) * 100 << "%" << endl;
        cout << "Fail : test [";
        for (int i = 0; i < result.size() - 1; i++)
        {
            cout << result[i] << ", ";
        }
        cout << result[result.size() - 1] << "]\n";
        cout << "link check comparefile: https://www.diffchecker.com/text-compare/" << endl;
    }
}
void test(string inputFile)
{
    // ! Position constructor get set str isEqual
    configuration(inputFile);

    string posStrSher = "(" + to_string(sherlock_init_pos[0]) + "," + to_string(sherlock_init_pos[1]) + ")";
    string posStrWat = "(" + to_string(watson_init_pos[0]) + "," + to_string(watson_init_pos[1]) + ")";
    Position posSher(posStrSher);
    OUTPUT << "Position string constructor : ";
    OUTPUT << "Pos " + posStrSher << endl
           << "Get row col : (" << posSher.getRow() << "," << posSher.getCol() << ")" << endl;
    OUTPUT << "Set " + posStrWat << endl;
    posSher.setRow(watson_init_pos[0]);
    posSher.setCol(watson_init_pos[1]);
    OUTPUT << "Get row col : (" << posSher.getRow() << "," << posSher.getCol() << ")" << endl;
    OUTPUT << "Position str : " << posSher.str() << endl;

    OUTPUT << "IsEqual old Position: " << ((posSher.isEqual(sherlock_init_pos[0], sherlock_init_pos[1])) ? "True" : "False") << endl;
    OUTPUT << "IsEqual Watson Position: " << ((posSher.isEqual(watson_init_pos[0], watson_init_pos[1])) ? "True" : "False") << endl;

    // ! Map test

    Position posWall[100];
    for (int i = 0; i < num_walls; i++)
    {
        posWall[i] = Position(arr_walls[i][0], arr_walls[i][1]);
    }
    Position posFakeWall[100];
    for (int i = 0; i < num_fake_walls; i++)
    {
        posFakeWall[i] = Position(arr_fake_walls[i][0], arr_fake_walls[i][1]);
    }

    Map map = Map(map_num_rows, map_num_cols, num_walls, posWall, num_fake_walls, posFakeWall);
    OUTPUT << "Map Check : " << map.getNumRows() << "x" << map.getNumCols() << endl;
    for (int i = -1; i < map_num_cols; i++)
    {
        if (i == -1)
            OUTPUT << setw(5) << "";
        else
            OUTPUT << setw(5) << i;
    }
    OUTPUT << endl;
    for (int i = 0; i < map.getNumRows(); i++)
    {
        OUTPUT << setw(5) << i;
        for (int j = 0; j < map.getNumCols(); j++)
        {
            int idx = (int)map.getElementType(i, j);
            string nameElement[3] = {".", "W", "F"};
            OUTPUT << setw(5) << nameElement[idx];
        }
        OUTPUT << endl;
    }
    // ! isValid
    OUTPUT << "IsValid (" << -1 << "," << map_num_cols / 2 << ",Watson," << 0 << ") : "
           << ((map.isValid(-1, map_num_cols / 2, MovingObject::WATSON, 0))
                   ? "True"
                   : "False")
           << endl;
    OUTPUT << "IsValid (" << map_num_rows / 2 << "," << -1 << ",Watson," << 0 << ") : "
           << ((map.isValid(map_num_rows / 2, -1, MovingObject::WATSON, 0))
                   ? "True"
                   : "False")
           << endl;
    OUTPUT << "IsValid (" << 0 << "," << map_num_cols << ",Watson," << 0 << ") : "
           << ((map.isValid(0, map_num_cols, MovingObject::WATSON, 0))
                   ? "True"
                   : "False")
           << endl;
    OUTPUT << "IsValid (" << map_num_rows << "," << 0 << ",Watson," << 0 << ") : "
           << ((map.isValid(map_num_rows, 0, MovingObject::WATSON, 0))
                   ? "True"
                   : "False")
           << endl;

    OUTPUT << "IsValid (" << -1 << "," << -1 << ",UNKNORW," << 0 << ") : "
           << ((map.isValid(-1, -1, MovingObject(4), 0))
                   ? "True"
                   : "False")
           << endl;
    OUTPUT << "IsValid (" << 0 << "," << 0 << ",UNKNORW," << 0 << ") : "
           << ((map.isValid(0, 0, MovingObject(4), 0))
                   ? "True"
                   : "False")
           << endl;

    OUTPUT << "IsValid (" << 0 << "," << 0 << ",Watson," << 0 << ") : "
           << ((map.isValid(0, 0, MovingObject::WATSON, 0))
                   ? "True"
                   : "False")
           << endl;
    OUTPUT << "IsValid (" << 0 << "," << 0 << ",Sherlock," << 0 << ") : "
           << ((map.isValid(0, 0, MovingObject::SHERLOCK, 0))
                   ? "True"
                   : "False")
           << endl;
    OUTPUT << "IsValid (" << 0 << "," << 0 << ",Criminal," << 0 << ") : "
           << ((map.isValid(0, 0, MovingObject::CRIMINAL, 0))
                   ? "True"
                   : "False")
           << endl;

    OUTPUT << "IsValid (" << 0 << "," << 0 << ",Robot," << 0 << ") : "
           << ((map.isValid(0, 0, MovingObject::ROTBOT, 0))
                   ? "True"
                   : "False")
           << endl;

    if (num_walls != 0)
    {
        OUTPUT << "Wall Check : " << endl;
        OUTPUT << "IsValid (" << arr_walls[0][0] << "," << arr_walls[0][1] << ",Sherlock," << 0 << ") : "
               << ((map.isValid(arr_walls[0][0], arr_walls[0][1], MovingObject::SHERLOCK, 0))
                       ? "True"
                       : "False")
               << endl;

        OUTPUT << "IsValid (" << arr_walls[0][0] << "," << arr_walls[0][1] << ",Watson," << 0 << ") : "
               << ((map.isValid(arr_walls[0][0], arr_walls[0][1], MovingObject::WATSON, 0))
                       ? "True"
                       : "False")
               << endl;

        OUTPUT << "IsValid (" << arr_walls[0][0] << "," << arr_walls[0][1] << ",Criminal," << 0 << ") : "
               << ((map.isValid(arr_walls[0][0], arr_walls[0][1], MovingObject::CRIMINAL, 0))
                       ? "True"
                       : "False")
               << endl;

        OUTPUT << "IsValid (" << arr_walls[0][0] << "," << arr_walls[0][1] << ",Robot," << 0 << ") : "
               << ((map.isValid(arr_walls[0][0], arr_walls[0][1], MovingObject::ROTBOT, 0))
                       ? "True"
                       : "False")
               << endl;
    }
    if (num_fake_walls != 0)
    {
        OUTPUT << "FakeWall Check : " << endl;

        OUTPUT << "IsValid (" << arr_fake_walls[0][0] << "," << arr_fake_walls[0][1] << ",Sherlock," << 0 << ") : "
               << ((map.isValid(arr_fake_walls[0][0], arr_fake_walls[0][1], MovingObject::SHERLOCK, 0))
                       ? "True"
                       : "False")
               << endl;
        OUTPUT << "IsValid (" << arr_fake_walls[0][0] << "," << arr_fake_walls[0][1] << ",Criminal," << 0 << ") : "
               << ((map.isValid(arr_fake_walls[0][0], arr_fake_walls[0][1], MovingObject::CRIMINAL, 0))
                       ? "True"
                       : "False")
               << endl;
        OUTPUT << "IsValid (" << arr_fake_walls[0][0] << "," << arr_fake_walls[0][1] << ",Robot," << 0 << ") : "
               << ((map.isValid(arr_fake_walls[0][0], arr_fake_walls[0][1], MovingObject::ROTBOT, 0))
                       ? "True"
                       : "False")
               << endl;

        OUTPUT << "IsValid (" << arr_fake_walls[0][0] << "," << arr_fake_walls[0][1] << ",Watson," << 0 << ") : "
               << ((map.isValid(arr_fake_walls[0][0], arr_fake_walls[0][1], MovingObject::WATSON, 0))
                       ? "True"
                       : "False")
               << endl;
        OUTPUT << "IsValid (" << arr_fake_walls[0][0] << "," << arr_fake_walls[0][1] << ",Watson," << 900 << ") : "
               << ((map.isValid(arr_fake_walls[0][0], arr_fake_walls[0][1], MovingObject::WATSON, 900))
                       ? "True"
                       : "False")
               << endl;
    }
}

int main(int argc, char *argv[])
{
    cout << "Start program assignments 1 DSA" << endl;
    int start = 0, end = 0;
    if (argc == 1)
    {
        start = 1;
        end = 200;
    }
    else if (argc == 2)
    {
        start = stoi(argv[1]);
        end = stoi(argv[1]);
    }
    else if (argc == 3)
    {
        start = stoi(argv[1]);
        end = stoi(argv[2]);
    }
    for (int i = start; i <= end; i++)
    {
        // cout << i << " ";
        string folderr = "testcase/output/output";
        // string folderr = "testcase/expect/expect";
        string inputFile = "testcase/input/input" + to_string(i) + ".txt";
        string outputFile = folderr + to_string(i) + ".txt";
        configuration(inputFile);
        OUTPUT.open(outputFile);
        test(inputFile);
        OUTPUT.close();
    }
    comparefile(start, end);
}
