ACTUAL=actual.test

for FILE in *; do
    if [[ $FILE == *.clox ]]; then
        EXPECTED="${FILE%.*}.expected"
        if [[ -f $EXPECTED  ]]; then
            rm $ACTUAL
            echo "== Running $FILE =="
            ../clox $FILE >> $ACTUAL 2>&1
            echo $FILE
            echo $EXPECTED
            if cmp -s $ACTUAL $EXPECTED; then
                echo '== Passed  '
            else 
                echo '== Failed   '
                exit 1
            fi
        fi
    fi
done

echo $HASERROR