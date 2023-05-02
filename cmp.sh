echo "CK MOONLANDER COMPILING............"
make clean && make moonlander:ckMoonlander

if [ -e ./.build/moonlander_ckMoonlander.bin ]; then
    if [ -e ~/Desktop/moonlander_ckMoonlander.bin ]; then
        rm ~/Desktop/moonlander_ckMoonlander.bin
    fi
    cp ./.build/moonlander_ckMoonlander.bin ~/Desktop/
    open ~/Desktop
    echo "DONE! :)"
else
    echo "FAILED :("
fi

