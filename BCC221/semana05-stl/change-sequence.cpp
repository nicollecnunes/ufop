#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    vector<int> vec = {9,60,70,8,45,87,90}; //7 itens
    vector<int> vec2(11,0); //11 itens: 0,0,0,0...

    //copiar (tamanho destino >= fonte)
    copy(vec.begin(), vec.end(), vec2.begin()); //source VEC

    vec2.assign(11,0);//11 itens: 0,0,0,0...
    copy_if(vec.begin(), vec.end(), vec2.begin(), [](int x){return  x>80;});
    //vec2 = 87,90,0,0,0,0,0,0,0,0,0

    vec2.assign(11,0);
    copy_n(vec.begin(), 4, vec2.begin());
    //vec2 = 9,60,70,8,0,0,0,0,0,

    vec2.assign(11,0);
    copy_backward(vec.begin(), vec.end(), vec2.end());
    //vec2: 0,0,00,0,0,0,0,9,60,70,8,45,87,90

    // transformar
    vec2 = vec;
    vector<int> vec3(11,0);
    transform(vec.begin(), vec.end(), vec3.begin(), [](int x){return x-1;});
    //vec3: 8,59,69,7,44,86,89,0,0,0,0

    transform(vec.begin(), vec.end(), vec2.begin(), vec3.begin(),
    [](int x, int y){return x+y;});
    //vec3: 18,120,140,16,90,174,180,0,0,0,0


    // swap
    swap_ranges(vec.begin(), vec.end(), vec3.begin());
    //vec: 18,120,140,16,90,174,180
    //vec3: 9,60,70,8,87,90,0,0,0,0

    // fill
    fill(vec.begin(), vec.end(), 9);
    //vec=9,9,9,9,9,9

    vec.assign(7,0);
    fill_n(vec.begin(), 3,9); // 9,9,9,0,0,0,0
    generate(vec.begin(), vec.end(), rand); //numeros aleattorios

    vec.assign(7,0);
    generate_n(vec.begin(), 3, rand); //3 numeroa aleatorios

    // replace
    vec2.assign({9,60,70,8,45,87,90});
    replace(vec2.begin(), vec2.end(), 9, 6);
    //vec2: 6,60,70,8,45,87,90

    replace_if(vec2.begin(), vec2.end(), 
    [](int x){return x >80;}, 100);
    //vec2: 6,60,70,8,45,100,100

    return 0;
}