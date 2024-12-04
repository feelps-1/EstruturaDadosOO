#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>

bool quadEquation(double a, double b, double c, double *, double *);

bool quadEquation(double a, double b, double c, double *p1, double *p2){
    
    double delta {b*b - 4*a*c};

    if(delta < 0){
        return false;
    }else{
        double delta_root {sqrt(delta)};

        if(delta != 0){
            *p1 = (-b + delta_root) / (2*a);
            *p2 = (-b - delta_root) / (2*a);
        }else{
            *p1 = (-b + delta_root) / (2*a);
            *p2 = *p1;
        }

    }
    return true;
}

void processFile(const std::string& input_file_path, const std::string& output_file_path){
    double solution_1 {};
    double solution_2 {};

    std::ifstream input_file(input_file_path);

    if(!input_file.is_open()){
        std::cerr << "Error opening file!" << '\n';
        return;
    }

    int numLines;
    input_file >> numLines; 
    input_file.ignore();   

    std::ofstream output_file(output_file_path);
    if (!output_file.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    for (int i = 0; i < numLines; ++i) {
        std::string line;
        if (std::getline(input_file, line)) {
            std::istringstream iss(line);
            double a, b, c;
            if (iss >> a >> b >> c) {
                if(quadEquation(a, b, c, &solution_1, &solution_2)){
                    output_file << std::setprecision(2) << solution_1 << ' ' << std::setprecision(2) << solution_2 << '\n';
                }else{
                    output_file << "none" << '\n';
                }; 
            } 
        }
    }
}

int main(){
    std::string input_file {"input_file.txt"};
    std::string output_file {"output_file.txt"};

    processFile(input_file, output_file);

    return 0;
}
