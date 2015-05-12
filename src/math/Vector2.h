/**
 * @brief ICP project 2015 (Maze game)
 * @authors xmalin26, xmasek15
 */

#ifndef ICP2015CLIENT_VECTOR2_H
#define ICP2015CLIENT_VECTOR2_H


class Vector2 {

private:
	int xpos, ypos;

public:
	Vector2(int x = 0, int y = 0);
	~Vector2();

	int x() const;
	int y() const;
	int &rx();
	int &ry();

	void setX(int x);
	void setY(int y);

	void set(int x, int y);
	void move(int dx, int dy);
	void move(const Vector2 &vec);
};


#endif //ICP2015CLIENT_VECTOR2_H
