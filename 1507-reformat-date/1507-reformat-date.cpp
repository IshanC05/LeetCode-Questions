class Solution {
public:
    string getMonth(string m){
        
        if(m == "Jan")  return "01";
        else if(m == "Feb")  return "02";
        else if(m == "Mar")  return "03";
        else if(m == "Apr")  return "04";
        else if(m == "May")  return "05";
        else if(m == "Jun")  return "06";
        else if(m == "Jul")  return "07";
        else if(m == "Aug")  return "08";
        else if(m == "Sep")  return "09";
        else if(m == "Oct")  return "10";
        else if(m == "Nov")  return "11";
        return "12";
        
    }
    
    string reformatDate(string date) {
        
        bool space = false;
        
        string a = "", b = "", month = "";
        
        for(int i = 0; i < date.size(); i++){
            
            if(date[i] == ' '){
                
                space = true;
                
                continue;
                
            }
            
            if(date[i] >= '0' && date[i] <= '9'){
                
                if(!space){
                    
                    a.push_back(date[i]);
                    
                }else{
                    
                    b.push_back(date[i]);
                }
                
            }else{
                
                if(space){
                    
                    month.push_back(date[i]);
                    
                }
                
            }
            
        }
        
        string monthFind = getMonth(month);
        
        if(a.size() == 1)   a = "0" + a;
        
        return (b + "-" + monthFind + "-" + a);
    }
};