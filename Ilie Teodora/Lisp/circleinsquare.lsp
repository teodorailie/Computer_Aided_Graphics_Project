(defun c:circleinsquare ( / )
  (setq ss (ssget "x" '((0 . "CIRCLE"))))   ; selects the circles
  (setq i 0)                                ; 'i'- counter
  (repeat (sslength ss)
    (setq entName (ssname ss i))
    (setq ent (entget entName))
    
    (setq centru (cdr (assoc 10 ent)))  ; finds the coordinates of the center
    (setq x (car centru))               ; firts coordinate
    (setq y (cadr centru))              ; second coordinate
    (setq raza (cdr (assoc 40 ent)))    ; finds the length of the radius
    (setq corner1 (list (- x raza) (- y raza)))  ; square's first corner coordinates
    (setq corner2 (list (+ x raza) (+ y raza)))  ; square's second corner coordinates
    (command "rectang" corner1 corner2)          ; draws the square
    (setq i (+ 1 i))                    ; counter 'i' augmentation 
    )
  (princ)
  )