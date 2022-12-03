namespace practica
{
    //П12-2-3 Реализуйте метод сортировки пузырьком с использованием не зависящего от размера файла количества памяти.
    int P1223()
    {
        std::ifstream infile("1.txt");
        std::string line;
        std::vector<int> v;
        int n;

        while (std::getline(infile, line))
            v.push_back(std::stoi(line));

        for(auto& i : v)
            printf("After [%i]\n",i);

        printf("Size: %i\n", v.size());
        for (int i = 0; i < v.size(); i++) {
            bool flag = true;
            for (int j = 0; j < v.size() - (i + 1); j++) {
                if (v[j] > v[j + 1]) {
                    flag = false;
                    std::swap(v[j], v[j + 1]);
                }
            }
            if (flag) {
                break;
            }
        }
        std::ofstream out;   
        out.open("1.txt");               
        for(auto& i : v)
        {
            out << i << std::endl;
            printf("Before: [%i]\n",i);
        }
        system("pause");
        return 0;
    }
}