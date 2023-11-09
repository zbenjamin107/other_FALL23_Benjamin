#|
zach benjamin
CS-3210-10
DrRacket
|#

; 1) sphere-vol calculates the volume of a sphere given the radius
(define sphere-vol 
  (lambda (r)
    (/ (* (expt r 3) 3.14 4) 3)));v = r^3 * 4/3 * π

; 2) pow will take the 2 parameters. returns the 1st parameter to the power of the 2nd parameters
(define pow
  (lambda (x y)
    (if (= y 0) ; anything to the power of 0 is one
        1
        ( if ( = y 1) ;anything to the power of one is itself. check for these two things first
             (* x 1)
             ( if ( > y 0) ; i noticed i dont need this for some reason but i put it there for good practice. scheme does nothing if y is negative i found
                      (* x (pow x (- y 1))))))));this will sort of loop until it has gone down to the power of one or zero
         

;3) count will return the number of zeros in a given list of numbers
(define count
  (lambda (x)
    (if (null? x); if empty then return zero
        0
        ( if ( = (car x) 0); this will loop a while since we will keep calling the function
                 (+ 1 (count (cdr x))); if the element is a zero then return plus 1
                     ( + 0 (count (cdr x)))))));if not then add nothing

;4)count the number of items in a list
(define len
  (lambda (x)
      (if (null? x); if there is nothing then return 0
          0
          (+ 1 (len (cdr x)))))); do it again with the top element removed. Do this until there is nothing left


;flatten is a function from class that i use. Thank you Prof Dude!
; (flatten '((1 5 6) 7 (2 4) 54 42 ((3))))
(define flatten
  (lambda (x)
    (cond ((null? x)'())
          ((list? x) (append (flatten (car x)) (flatten (cdr x))))
          (else (cons x '())))))
    
;5) rev function will reverse the order of the list
(define rev
  (lambda (x)
    (cond ((null? (cdr x)) x )
          (else (flatten (list(rev(cdr x)) (car x)))))))

(define square
  (lambda (x)
    (* x x)))
;6)twice will take a function and a parameter and do the function twice on the parameter
(define twice
  (lambda (f)
    (lambda (x)
      (f(f x)))))

;7) inc_n will increment a parameter n times
(define inc_n
  (lambda (x)
    (lambda (n)
      (+ x n))))

;8)a memeber function will return true if the parameter is a member of the function
(define member1
  (lambda (x y)
    (cond ((null? y) #false)
          (else (if ( = (car y) x)
            #true
           (member1 x (cdr y)))))))
    
;8)b insert adds a number to a list
(define insert
  (lambda (x y)
    (cons x y)))
                
