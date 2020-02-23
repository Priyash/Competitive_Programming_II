#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <map>
#include <algorithm>


using namespace std;

class Cashier
{
    int n;
    int discount;
    vector<int> products;
    vector<int> prices;
    int count;
    double bill = 0.0;
    int mod = 0;
    double pct;
    unordered_map<int, int> productPriceMap;

public:
    Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
    {
        this->n = n;
        this->mod = n;
        this->discount = discount;
        this->products = products;
        this->prices = prices;
        this->count = 0;
        this->pct = (double)((100.0 - discount) / 100.0);
        for (int i = 0; i < products.size(); i++)
        {
            productPriceMap[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount);
};


double Cashier::getBill(vector<int> product, vector<int> amount)
{
    count++;
    bill = 0.0;
    for (int pid = 0; pid < product.size(); pid++)
    {
        bill += productPriceMap[product[pid]] * amount[pid];
    }
    return count % mod ? bill : bill * pct;
}

int main()
{
       vector<int> products = {1, 2, 3, 4, 5, 6, 7};
       vector<int> prices = {100, 200, 300, 400, 300, 200, 100};
       Cashier* cashier = new Cashier(3, 50, products, prices);
    
       vector<int> product1 = {1,2};
       vector<int> amount1 = {1,2};
    
       vector<int> product2 = {3,7};
       vector<int> amount2 = {10,10};
    
       vector<int> product3 = {1,2,3,4,5,6,7};
       vector<int> amount3 = {1,1,1,1,1,1,1};
       double  bill = cashier->getBill(product1, amount1);
       cout<<"Bill : " <<bill<<endl;
    
       double  bill2 = cashier->getBill(product2, amount2);
       cout<<"Bill : " <<bill2<<endl;
    
       double  bill3 = cashier->getBill(product3, amount3);
       cout<<"Bill : " <<bill3<<endl;
    return 0;
}