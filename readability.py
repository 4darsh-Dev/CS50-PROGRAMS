
# Program that will find what piece of text is suitable for learning for a particular Grade students based upon Coleman-Liau's formula
myText = input("Text: ")

alphaList = ['A','B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

endList = ['.', '!', '?']

# counting no of words
def nWords(text):
    wList = myText.split(" ")
    nWord = len(wList)
    return nWord

# counting letters n the text
def lCounter(text, alphaList):
    lCount = 0
    for t in text:
        t = t.lower()
        for a in alphaList:
            a = a.lower()
            if t == a:
                lCount +=1

    return lCount

# counting sentences in the text
def senCounter(text, endList):
    senCount = 0
    tList = list(text)

    for t in tList:
        if t in endList:
            senCount +=1

    return senCount

# performing calculation according to Coleman-Liau's Formula

def readCalc(text, alphaList, endList):
    lCount = lCounter(myText, alphaList)
    wCount = nWords(myText)
    sCount = senCounter(myText, endList)

    L = (lCount*100)/wCount
    S = (sCount*100)/wCount

    colValue = 0.0588 * L - 0.296 * S - 15.8

    # Roundin the values
    colValue = round(colValue)
    return colValue



output = readCalc(myText, alphaList, endList)

# Dividing the grade levels
if output > 16:
    print("Grade 16+")
elif output < 1:
    print("Before Grade 1")
else:
    print(f"Grade {output}")















