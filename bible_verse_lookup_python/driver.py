'''
zach benjamin
Bible look up IN PYTHON!!
due: 11/12/23

prompted by the terminal, a user will input a bible book, chapter, and verse. There are abbreviations for books in Bible_abbreviations.csv.
program will print the verse if it is a valid entry. if not it will complain
'''

#this little guy will take the book,chapter and verse line from bible.txt 
def print_verse(b,c,l):
    if len(l) < 77:#if the verse is les than 80 in length then just print it
        print("{} {}:{}".format(b,c,l))
    #this next one will print in lines of 80. print character by character
    else:
        length = len(b) + len(c)
        i = length
        print(b,c,end=": ")
        for char in l:
            if i%77 == 0 and i >= 77:
                print()
            print(char,end="")
            i+=1
            
        print()#new line for aesthetics
    #======opens file and prints verse to it======
    #f = open("verse.txt","a")
    #f.write("{} {}:{}".format(b,c,l))
    #f.close()

#as long as user wants more the program will ask for input. if the user ran this..
#..program we can assume they start with wanting more
more = "Y"

while more == "Y":
    book_found = False
    chapter_found = False
    verse_found = False
    #get the book, chapter and verse. everything is to upper so that it is easier to compare
    print("Please enter the reference of the verse you would like to retrieve")
    book = input(" the book: ").upper()
    chapter = input(" the chapter: ")
    verse = input(" the verse: ")
    versedigits = len(verse)
    #check to see if the book is abbreviated input
    abrv = open("Bible_abbreviations.csv","r")
    lines = abrv.readlines()
    for line in lines:
        words = line.split(",")     #splits the line at the comma so i can access each word individually
        if words[0].upper() == book:#if the book input matches the abbreviation, then change the book input to be the actual name. 
            book = words[1].upper().rstrip() 
    #search our bible text for the passage
    bible = open("Bible.txt","r")
    lines = bible.readlines()
    for line in lines:
        #not only one of the following can execute at a time
        if line == "THE BOOK OF {}\n".format(book):
            book_found = True#you have found the book when you come to its name
        elif line == "CHAPTER {}\n".format(chapter) and book_found or line == "PSALM {}\n".format(chapter) and book_found:
            chapter_found = True#chapter found only after book is found
        elif line[0:versedigits] == verse and chapter_found:
            verse_found = True#verse found when book and chapter already found
        elif line[0:8] == "THE BOOK" and book_found:#when book is already found and come to next 'book of' title, then chpater not found or the(special case) last chapter of a book and the verse is not found
            if chapter_found:#if the book is found and chapter is found and come to next book, verse not found. special condition
                print('Chapter {} of {} does not have verse {}.'.format(chapter,book,verse))#ex. gen 50:30 would print chapter not found w/ out this catch
                break
            else:#else we are just missing a chapter
                print('The book of {} does not have chapter {}.'.format(book,chapter))
                break
        elif line[0:7] == "CHAPTER" and book_found and chapter_found :#when book and chapter are already found and come to next "chapter" title then chapter not found
             print('Chapter {} of {} does not have verse {}.'.format(chapter,book,verse))
             break
        #if all of our conditions are met then the reference if found..print it
        if (book_found and chapter_found and verse_found):
            print_verse(book,chapter,line)
            break
    #happens when we didnt find the book in the bible
    if not book_found:
        print('The Bible does not contain the book "{}".\n'.format(book))
    #ask if they want to keep going. the while loop will go again. make sure input is y or n
    more = input("Would you like to look up another verse (Y/N)?").upper()   
    while more != "Y" and more != "N":
        more = input("Would you like to look up another verse (Y/N)?").upper()
