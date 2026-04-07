class Robot {
public:
    int w, h, x, y, dir, perim;

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        perim = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        if (perim == 0) return;
        num %= perim;
        if (num == 0 && (x == 0 && y == 0)) dir = 3;
        while (num > 0) {
            if (dir == 0) {
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if (num > 0) dir = 1;
            } else if (dir == 1) {
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
                if (num > 0) dir = 2;
            } else if (dir == 2) {
                int move = min(num, x);
                x -= move;
                num -= move;
                if (num > 0) dir = 3;
            } else {
                int move = min(num, y);
                y -= move;
                num -= move;
                if (num > 0) dir = 0;
            }
        }
    }
    
    vector<int> getPos() {
        vector<int> res(2);
        res[0] = x;
        res[1] = y;
        return res;
    }
    
    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */