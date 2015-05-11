//
// Created by gelidus on 11.5.2015.
//

#ifndef ICP2015CLIENT_VECTOR2_H
#define ICP2015CLIENT_VECTOR2_H


class Vector2 {

private:
	int x, y;

public:
	Vector2(int x = 0, int y = 0);
	~Vector2();

	int getX() const;
	int getY() const;

	void setX(int x);
	void setY(int y);

	void set(int x, int y);
	void move(int dx, int dy);
	void move(const Vector2 &vec);
};


#endif //ICP2015CLIENT_VECTOR2_H
