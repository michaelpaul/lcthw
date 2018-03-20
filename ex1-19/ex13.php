<?php
$args = join(" ", array_fill(0, pow(2, 15), "banana"));
passthru("./ex13 $args");
echo "done\n";