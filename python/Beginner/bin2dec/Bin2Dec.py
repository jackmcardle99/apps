# function to process user input
def getInput():  
    
    while True:          
        number_check = False
        binary_num = input("\nPlease enter an 8 bit binary digit for conversion to decimal. E.g. 00010101 \n")
        bin_length = len(binary_num)
        count = 0
        
        #loop start
        for i in binary_num: #looping through string to ensure letters are 1 or 0
            if int(i) == 1 or int(i) == 0: #to check for only binary digits
                count +=1           
            if count == bin_length:
                number_check = True                
        #loop end
        
        #decision structure for validation
        if bin_length > 8 and number_check == True:
            print("\n - The number entered was more than 8 digits long. ")
            continue
        elif number_check == False and bin_length <= 8:
            print("\n - A non binary numeral was entered. (0 or 1) ")
            continue
        elif number_check == False and bin_length > 8:
            print("\n - Number entered was more than 8 digits long and contained non binary numeral. (0 or 1) ")
        elif bin_length <= 8 and number_check == True:
            convertBin(binary_num)
            

#function to convert binary to decimal
def convertBin(binary_num):
   
    bin_length = len(binary_num)
    decimal_num = 0
    current = None

    #loop start
    for x in binary_num:   
        bin_length -= 1 #this decreases the length by 1 on each iteration, in order to find powers
        current = (int(x) * 2 ** bin_length)  #current number is multiplied by 2, and then multiplied by its appropriate power
        decimal_num = decimal_num + current #adding each number to decimal number on each iteration
    #loop end
    print(str(binary_num) + " in decimal is: " + str(decimal_num))
        

        
print("\nThis program will take upto 8 binary digits and convert it into base 10, aka decimal. \n")
getInput()

