<!DOCTYPE HTML>
<html>
  <body>
    <h1>Projet de groupe pour créer un jeu similaire à Hordes.</h1>
    <h2>Cahier des charges</h2>
    <h3>Principe du jeu :</h3>
    <p>Des joueurs rassemblés dans une ville qui essayent de survivre à des attaques de zombies survenant ponctuellement à une heure donnée.</p>
    <p>Le but du jeu est de survivre le plus de jour, pour cela il faut coopérer avec les autres joueurs présents dans la ville. Un jour dans le jeu correspond à 10 minutes dans la vraie vie, le joueur doit donc faire toutes ses actions avant la fin du temps imparti.</p>
    <h3>Gameplay du jeu :</h3>
    <h4> Interface </h4>
    <p>Il y a deux interfaces graphiques, une lorsqu'on est dans la ville et une lorsqu'on est en dehors. Dans la ville, le joueur ne controle pas de personnage, il voit des "cases" cliquables qui lui permettent d'interagir avec ce qu'il veut. Par exemple, si le joueur clique sur la "case" maison, le jeu lui montre sa maison. En dehors de la ville, le joueur voit une carte composée de cases, la ville se situe sur la case au milieu. Les dimensions de la carte est 13*13 cases. Le joueur peut voir sur la carte des marqueurs qu'il peut créer, tel que l'emplacement de la ville ou sa position actuelle. Le joueur voit à côté de la carte la case sur laquelle il se situe. Il peut y voir son personnage immobile au centre de la case, des zombies si il y en a et des flèches situées aux 4 côtés de la case. Si le joueur clique sur une flèche il se déplace vers la case indiquée par la flèche. Par exemple, le joueur clique sur la flèche de gauche, il se déplace sur la case de gauche.</p>
    <h4> Action </h4>
    <p>Vous contrôlez un citoyen, il a :</p>
    <ul>
      <li>une barre de statut, qui indique des bonus et des malus</li>
      <li>un compteur de point d’action, le joueur à 6 points au début du jour et certaines actions nécessitent ces points. Le compteur se régénère chaque jour.</li>
      <li>une barre d’inventaire, où le joueur peut entreposer 4 objets + sa tenue sur lui.</li>
      <li>une maison, qu’il peut améliorer et où il peut entreposer jusqu’à 4 objets.</li>
    </ul>
    <p>Les citoyens sont dans une ville qui comporte 8 zones distinctes :</p>
    <ul>
      <li>un puit, où les citoyens peuvent prendre une ration d’eau, les rations d’eau sont limités, la partie commence avec 150 rations d’eau.</li>
      <li>une banque où les citoyens rangent les objets qu’ils veulent, on peut mettre autant d’objet qu’on veut..</li>
      <li>une zone nommée “citoyen”, c’est l’endroit où le joueur peut voir les autres joueurs présents dans la ville.</li>
      <li>un chantier où les joueurs peuvent utiliser des points d’action pour construire des infrastructures.</li>
      <li>une grande porte où les joueurs peuvent sortir de la ville. Ils voient aussi les défenses de la ville et la puissance de l'attaque des zombies qui sont représentés par des nombres. Si la puissance de l'attaque est plus grande que les défenses, des joueurs ont une chances de mourrir pendant l'attaque.</li>
      <li>un atelier où les joueurs peuvent transformer des ressources contre 3 points d’actions, par exemple transformer du bois en planche.</li>
      <li>un forum où les joueurs peuvent interagir sur différents sujets.</li>
      <li>une maison personnel à chaque joueur,dans cette zone il peut interagir avec ses objets, par exemple il peut boire et manger.</li>
    </ul>
    <p>Votre citoyen a plusieurs états de santé qui affectent en bien ou en mal vos actions :</p>
    <ul>
       <li>La fatigue, votre citoyen n'a plus de points d'actions, impossibilité alors de se déplacer.</li>
      <li>La soif , votre citoyen a besoin de boire avant de finir en état de déshydratation.</li>
      <li>L'état rassasié, indique que vous avez bu et/ou manger, donc répéter ces actions ne permet plus de récupérer des             points d'actions.</li>
       <li>La blessure, il faut soigner vôtre citoyen avant qu'il ne succombe de celle-ci, généralement un homme blessé meurt en deux jours.</li>
      <li>Drogué(e), vous avez utilisé des substances iliicites qui permettent de surmonter les états de fatigue,soif et de blessure.Cependant il ne faut pas abusé des drogues sinon vous tomberez dans la dépendance.</li>
      <li>Clair, vous n'avez pas consommé de drogue , vous évitez les dangers de la dépendance.</li>
      <li>Immunisé, vous avez consommé un médicament qui vous permet de guérir de vos blessures</li>
      <li>La terreur, vôtre citoyen a réussi à échapper à l'attaque de la horde, il en ressort terrorisé ses ations hors de la ville sont limités, et si il se retrouve face à un zombie il mourra paralysé par la peur.</li>
    </ul>
    <p>En dehors de la ville, vos actions sont différentes :</p>
    <ul>
      <li>Sur n'importe quelle case, vous voyez votre barre d'inventaire et vous pouvez interagir avec.</li>
      <li>Si vous êtes sur la case de la ville, vous pouvez rentrer dans la ville.</li>
      <li>Si vous êtes sur une case autre que celle de la ville vous pouvez :
        <ul>
          <li>Fouiller la zone, ce qui permet de trouver un objet aléatoire. Cet action ne peut être faite plus d'une fois sur la même zone.</li>
          <li>Attaquer des zombies si il y en a sur la case, cette action consomme un point d'action et détruit un zombie sur la zone.</li>
          <li>Fuir la zone si il y a des zombies, cette action est possible uniquement si il y a plus de joueurs que de zombies sur la case. Cette action est nécessaire si le joueur souhaite quitter une case comportant des zombies.</li>
        </ul>
      </li>
    </ul>
    <h4>Le déroulement d'une attaque de zombie:</h4>
    <ul>
      <li>Une attaque se déroule uniquement si le nombre de zombies est supérieur au nombre de défenses, une défense bloque un zombie.</li>
      <li>Il y a une attaque toutes les nuits, plus il y a de zombies dans la ville, plus les citoyens ont des chances de mourir.</li>
      <li>Chaque zombie va attaquer la maison d'un citoyen, le citoyen meurt si sa maison n'est pas assez fortifiée,autrement il repousse l'attaque des zombies mais rentre en état de terreur.</li>
  </body>
</html>
