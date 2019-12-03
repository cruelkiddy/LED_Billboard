
/* 
 *  @brief : Control send process according to the message received.
 *  @date : 5/18/2019
 *  
 *  @brief : modified to control LED State, refine code style and add comment
 *
 *  @brief : Coming to add comments
 *  @date : 12/3/2019
 */

#define Scroll 1
#define Static 0

String DisplayText = "AINB///";
int Mode = Scroll;
int Intensity = 2;

void Control_Send(String& rawString){
 
    int i = 0;int flag = 0;long num_value;int value_get = 0;int v = 0; int j = 0;
    
    String value[2]; value[0] = ""; value[1] = "";
    String rawText = "";
    char textBuffer[3] = "";
    
    while(value_get < 2){
        if(rawString.charAt(i) == '=')  {value_get++;i++;continue;};
        if(rawString.charAt(i) == '&')  {break;}
        value[value_get] += rawString.charAt(i);
        i++;
    }

    Serial.println(value[0]);
    Serial.println(value[1]);
    Serial.println(value[1].charAt(1));
    if(value[0].charAt(1) == 'W') {
        if(value[1].charAt(0) == 't')  {Mode = Scroll;}
        if(value[1].charAt(0) == 'f')  {Mode = Static;}
    }
    else if(value[0].charAt(1) == 'F'){
        num_value = value[1].toInt();
        Intensity = num_value;
        ledMatrix.setIntensity(Intensity);
        Serial.println("Intensity changed");
    }
    else if(value[0].charAt(1) == 'T'){
        
        if(value[1].indexOf("%") >= 0){
            i = 0;
            for( ; i < value[1].length(); i++){
                if(value[1].charAt(i) == '%'){
                      textBuffer[0] =  value[1].charAt(i+1);
                      textBuffer[1] =  value[1].charAt(i+2);
                      textBuffer[2] =  0;
                      sscanf(textBuffer, "%x", &v);
                      rawText += char(v);
                      i += 2;
                }
                else{
                     rawText += value[1].charAt(i);
                }
            }
            DisplayText = rawText;
        }
        else{DisplayText = value[1];}
        ledMatrix.setText(DisplayText);
        rawText = "";
        Serial.println("Text changed");
    }

}
