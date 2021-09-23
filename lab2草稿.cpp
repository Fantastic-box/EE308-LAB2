#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void First_Level(string str);
void Second_Level(string str);
void Third_Level(string str);
bool compareWithKeys(string str1, string str2);

int a = 0;
int total_num = 0;
int switch_num = 0;
int case_p = -1; //ÿ��switch״̬�¶�Ӧcase�������λ�� 
int case_num[100]= {0};
int p = -1;
int if_else[100] = {0};
int if_else_num = 0;
int if_else_d_num = 0;
int num_e_f = 0;
string str;
ifstream inFile;

const int key_num = 32;
const int key_max = 9;
const char key [key_num][key_max] = {"auto", "break", "case", "char", "const", "continue","default","do", 
                                     "double", "else", "enum","extern","float", "for", "goto", "if", 
                                     "int", "long", "register", "return", "short", "signed", "sizeof", "static", 
                                     "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

int main(){
	int i = 0;
	string path;
	int level;
	getline(cin, path);
	cin >> level;
    inFile.open(path.c_str());
    
    if(level == 1){
    	while(inFile.good()){
    	    getline(inFile, str);
    	    First_Level(str);
    	    
	        cout << "total num:" << total_num << endl;
        }
	}else if(level == 2){
		while(inFile.good()){
    	    getline(inFile, str);
    	    Second_Level(str);
    	    First_Level(str);
    	    
    	    cout << "total num:" << total_num << endl;
	        cout << "switch_num:" << switch_num << endl;
	        cout << "case_num:" ;
	
	        for(;i < switch_num;i++){
		        cout << case_num[i] << " ";
	        }
	        cout << "" << endl;
        }
	}else if(level == 3){
		while(inFile.good()){
    	    getline(inFile, str);
    	    Second_Level(str);
    	    First_Level(str);
    	    
    	    cout << "total num:" << total_num << endl;
	        cout << "switch_num:" << switch_num << endl;
	        cout << "case_num:" ;
	
	        for(;i < switch_num;i++){
		        cout << case_num[i] << " ";
	        }
	        cout << "" << endl;
	
	        cout << "if-else num::" << if_else_num << endl;
        }
	}else if(level >=4){
		while(inFile.good()){
    	    getline(inFile, str);
    	    Second_Level(str);
    	    First_Level(str);
    	    
    	    cout << "total num:" << total_num << endl;
	        cout << "switch_num:" << switch_num << endl;
	        cout << "case_num:" ;
	
	        for(;i < switch_num;i++){
		        cout << case_num[i] << " ";
	        }
	        cout << "" << endl;
	
	        cout << "if-else num::" << if_else_num << endl;
	        cout << "if-elseif-else num:" << if_else_d_num << endl;
        }
	}
    
    inFile.close();
    
    printLine();
    
    return 0;  
}

//���ҿ����ǹؼ��ʵ���� 
void First_Level(string str){
	int l, i, j, k;//i��j���ڼ�����l���ڽ�ȡstrʱ�Թؼ��ʵĳ��ȼ��㣬k���ڽ�ȡstrʱ�ĳ��ȼ��� 
	bool find_end = false;//���ڳ��ֿ���ע��ʱ�Ľ�βѰ�� 
	for(i = 0;i < str.length();i++){
		
		if(str[i] >= 'A' && str[i] <= 'z'){
			
			for(j = 0;j < key_num;j++){//��str��ؼ����������ÿһ�������ó����� 
				
				if(compareWithKeys(str, key[j])){
					l = sizeof(key[j]);//�൱�������ո��ҵ�������� 
			    
				    string st = "";//��ȡ�ؼ���֮��str��ʣ�ಿ�ּ�Ϊst 
			        for(k = l;k < str.length();k++){
				        st = st + str[k];
			        }
			
			        str = st;//����ȡ�������¸���str 
					i = i + sizeof(key[j]);//�൱�������ո��ҵ�������� 
					total_num++;
					
				}else{
					
				}
			}
			
		
		}else if(str[i] == '"' || str[i] == '#' || (str[i] == '/' && str[i + 1] == '/')){//����˫�»��߻���#����Ϊ�����Ϊע�ͻ������ 
			break;
		}else if(str[i] == '/' || str[i + 1] == '*'){//����ע�� 
			
			for(j = i + 1;j < str.length() - 1;j++){
				if(str[j] == '*' && str[j + 1] == '/'){
					i = j + 2;
				}else{
					if(j == str.length() - 1){
						find_end = true;
				    }
				}
			}
			
			while(find_end){
				getline(inFile, str);
				for(j = 0;j < str.length() - 1;j++){
					if(str[j] == '*' && str[j + 1] == '/'){
						find_end = false;
						getline(inFile, str);
					}
				}
			}
		}else{
			
		}
		
	}
	
}

//�Ա�str��key������ȷ�� 
bool compareWithKeys(string str1, string str2){
	int i, j, z = 0;//z������key���� 
	
	if(str2.length() > str1.length()){
		
	}else{
		for(i = 0;i < str1.length() - str2.length();i++){
		
		    for(j = i;(j - i) < str2.length();j++){
			    if(str1[j] == str2[z]){
				    
					if(z == str2.length() - 1 && (str1 [j + 1] <= 'A' || str1[j + 1] >= 'z' )){//Ψһ���ֹؼ��ʵ����
					    return true;
				    }else{
					    z++;
				    }
				
			    }else if(str1[j] == '"' || str1[j] == '/'){//����"����/����Ϊ��Ч�����ѽ���
			    	i = str1.length() - str2.length();//������ѭ�� 
					break;
				}else{
				    break;
			    }
			    
		    }
		    z = 0;
		    
	    }
	}
	return false;
}

void Second_Level(string str){
	int i, j, s = 0, c = 0;
	
	//����switch 
	if(str.length() < sizeof(key[25])){
		
	}else{
		
		for(i = 0;i < str.length() - sizeof(key[25]);i++){
			for(j = i;(j - i) < sizeof(key[25]);j++){
				if(str[j] == key[25][s]){
					if(s == 5){
						switch_num++;
                        case_p++;//��switch��Ӧcase�������������λ��
					}
					s++;
				}else{
					break;
				}
			}
			s = 0;
		}
	}
	
	//����case 
	if(str.length() < sizeof(key[2])){
		
	}else{
		
		for(i = 0;i < str.length() - 4;i++){
			for(j = i;(j - i) < 4;j++){
				if(str[j] == key[2][c]){
					if(c == 3){
						case_num[case_p]++;//��֪��switch״̬�µ�case�������� 
					}
					c++;
				}else{
					break;
				}
			}
			c = 0;
		}
		
	}
	
}
void Third_Level(string str){
	
	int i, j;
	
	//����if
	if(str.length() < 2){
		
	}else{
		
		for(i = 0;i < str.length() - sizeof(key[16]);i++){
			if(str[i] == 'i' && str[i + 1] == 'f' && str[i - 2] != 'e'){
				p++;
				if_else[p] = 0;
			}
		}
		
	}
	
	//����else 
	if(str.length() < 4){
		
	}else{
		
		for(i = 0;i < str.length();i++){
			if(str[i] == 'e' && str[i + 1] == 'l' && str[i + 2] == 's' && str[i + 3] == 'e' && str[i + 5] != 'i'){
				
				p++;
				if_else[p] = 2;
				
				for(j = p;j > 0;j--){
					if(if_else[j] == 2){
						if_else[j] = 0;
						p--;
					}else if(if_else[j] == 1){
						num_e_f++;
						if_else[j] == 0;
						p--;
					}else{
						if(num_e_f == 0){
							
							if_else_num++;
						}else{
							
							if_else_d_num++;
						}
						p--;
						j = 0;
						num_e_f = 0;
					}
				}
				
			}
		}
		
	}
	
	//����else-if
	if(str.length() < 7){
		
	}else{
		
		for(i = 0;i < str.length();i++){
			if(str[i] == 'e' && str[i + 1] == 'l' && str[i + 2] == 's' && str[i + 3] == 'e' && str[i + 5] == 'i'){
				p++;
				if_else[p] = 1;
				
			}
		}
		
	}
}
