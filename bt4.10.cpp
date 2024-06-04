#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

/*
Ho va ten: Nguyen Hoang Nam
MSSV: 20225213
Ma lop: 738920
*/

//Chia một chuỗi thành các từ ngăn cách bởi dấu phẩy và trả về vector chứa từ đó
vector<string> split(const string& str, char delimiter) {
    vector<string> result;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

//Tính giá trị TF của từ
double calculateTF(int f_td, int max_f_d) {
    return 0.5 + 0.5 * (double)f_td / max_f_d;
}

//Tính giá trị IDF của từ
double calculateIDF(int N, int df_t) {
    return log2((double)N / df_t);
}

int main() {
    int N;
    cin >> N;
    cin.ignore();  
    
    vector<string> documents(N);
    unordered_map<string, int> documentFrequency;
    vector<unordered_map<string, int>> termFrequencies(N);
    vector<int> maxFrequencies(N, 0);

    //Đọc từng văn bản và tách văn bản thành các từ ngăn cách bởi dấu phẩy, đếm số từ
    for (int i = 0; i < N; ++i) { 
        getline(cin, documents[i]);
        vector<string> words = split(documents[i], ',');
        
        unordered_map<string, int> wordCount;
        
        for (const string& word : words) {
            wordCount[word]++; //Số lần xuất hiện từng từ
            maxFrequencies[i] = max(maxFrequencies[i], wordCount[word]); //Số lần xuất hiện nhiều nhất của từ i
        }

        termFrequencies[i] = wordCount;

        for (const auto& entry : wordCount) {
            documentFrequency[entry.first]++; //Số lượng văn bản chứa mỗi từ
        }
    }

    int Q;
    cin >> Q;
    cin.ignore();  

    //Xử lí từng truy vấn
    for (int i = 0; i < Q; ++i) {
        string query;
        getline(cin, query);
        vector<string> queryWords = split(query, ',');

        vector<double> scores(N, 0.0);

        for (const string& word : queryWords) {
            if (documentFrequency.find(word) != documentFrequency.end()) {
                double idf = calculateIDF(N, documentFrequency[word]); //Tính giá trị IDF của từng từ trong truy vấn

                for (int j = 0; j < N; ++j) {
                    if (termFrequencies[j].find(word) != termFrequencies[j].end()) {
                        double tf = calculateTF(termFrequencies[j][word], maxFrequencies[j]);//Tính giá trị TF của từng từ trong văn bản
                        scores[j] += tf * idf;
                    }
                }
            }
        }

        //TÌm văn bản có điểm số cao nhất
        int bestIndex = 0;
        double bestScore = scores[0];
        for (int k = 1; k < N; ++k) {
            if (scores[k] > bestScore || (scores[k] == bestScore && k < bestIndex)) {
                bestIndex = k;
                bestScore = scores[k];
            }
        }

        cout << bestIndex + 1 << endl;  //+1 để chuyển từ chỉ số 0-based sang 1-based
    }

    return 0;
}
