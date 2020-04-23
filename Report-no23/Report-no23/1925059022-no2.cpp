/*学籍番号　1925059022
氏名　小川拓馬
題名　弾幕除けゲーム

使用方法
ウィンドウ左上から赤い球が流れてくるので、それをよけるゲーム。
操作はマウスボタンで行う。
右：キャラクターが右に移動。
左：キャラクターが左に移動。
当たり判定や得点の表示などはない。（やりたかったけど）
弾幕はNUMの数だけ出てくる。

工夫した点
キャラクターがレーンの外に行かないように、プログラムを書いたこと。
状況が見やすいように、視点を変えたこと。
完全な人型ではないが、キャラクターを階層構造によって作成したこと。
マクロで定義しているSPEEDの値を変えることで、弾幕の速度が変更できるようにしたこと。
レーンの回転の向きがよくわかるように、カリングを使用したこと。
乱数で、弾幕の流れを決めたので、偏りがあるとしても、ゲーム性は高まっていると考える。

悔しかった点
スコア表示をとゲームの終了の機能を付加したかった。
各弾幕は、Ｘ座標を正の向きで動き、レーンに乗る前に、Ｚ座標は一意に決定する。
したがって、キャラクターのＸ座標とレーン番号が一致すれば、当たり判定の一種として、よりゲーム性
が高められたと考える。
それに従って、変数scoreと変数countを使用することを考えた。
各変数の役割は以下の通りである。
score：弾幕をよけた際、１加算される。よって、scoreの最大値はNUMである。
count：弾幕にあたった際に１加算する。count>=3でゲームが終了すなわちglTranslated(r,0,0)の入ったループをブレイクする。
*/
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#define NUM 200//弾幕の数
#define SPEED 5//弾幕のスピード
int move=2;//キャラクターの動きを統括する変数。２は真ん中のレーンを指す。
double cos30 = 1.7320508 / 2;
//int score = 0;
//int count = 0;
int enemy[NUM][3];//弾幕の座標
int ex[NUM],ey[NUM], ez[NUM];//代入用の配列
int rn[NUM];//各弾幕のレーン番号左から０，１，２，３，４とする。
int r=0;//移動距離
void idle(void) {
	glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(7, 8, 5, 0, 0, 0, 0, 1, 0);
	glPushMatrix();
	glTranslated(0, 0, -20);//基準となるレーンの描画
	glPushMatrix();
	glColor3d(0.2, 0.2, 0.2);
	glScaled(100, 1, 2);
	glutSolidCube(4);
	glColor3d(1, 1, 1);
	glutWireCube(4);
	glPopMatrix();
	for (int i = 0; i < 4; i++) {
		glTranslated(0, 0, 10);//残り４つのレーンの描画
		glPushMatrix();
		glColor3d(0.2, 0.2, 0.2);
		glScaled(100, 1, 2);
		glutSolidCube(4);
		glColor3d(1, 1, 1);
		glutWireCube(4);
		glPopMatrix();
	}
	glTranslated(0, 0, 10*(move-2));
	glTranslated(45, 6 + 5 * cos30, -20);//棒人間の頭の中心の高さ
	int cz = -20 + 10 * (move - 2);
	if (cz > 20)
	{
		cz = 20;
	}
	else if (cz < -20) {
		cz = -20;
	}
	glPushMatrix();
	glColor3d(0, 1, 1);
	glutSolidSphere(2, 100, 100);
	glPopMatrix();
	glTranslated(0, -4.5, 0);
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glColor3d(1, 1, 0);
	glScaled(1, 5, 1);
	glutSolidCube(1);//胴体
	glPopMatrix();
	glRotated(30, 1, 0, 0);
	glTranslated(0, -5, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1);//腕
	glPopMatrix();
	glRotated(-30, 1, 0, 0);
	glTranslated(0, -5, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1);//腕
	glPopMatrix();
	glTranslated(0, -2.5, 0);
	glColor3d(1, 1, 0);
	glRotated(30, 1, 0, 0);
	glScaled(1, 5, 1);
	glutSolidCube(1);//足
	glPopMatrix();
	glRotated(-30, 1, 0, 0);
	glTranslated(0, -5, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1);//足
	glPopMatrix();
	glPopMatrix();

	glTranslated(0, 6, 0);
	r++;
	for (int j = 0; j < SPEED; j++) {
		glTranslated(r, 0, 0);
	}
	
	for (int i = 0; i < NUM; i++) {//射出の間隔
		glTranslated(-10, 0, 0);
		glPushMatrix();
		glTranslated(0, 0, (GLdouble)ez[i]);//弾幕の乗るレーンの決定
		glColor3d(1, 0, 0);
		glutSolidSphere(2, 100, 100);
		glPopMatrix();
		/*enemy[i][0] = ex[i] - 10 * i;
		if (enemy[i][0] == 50+10*i && ez[i] == cz) count++;
		if (count >= 3) {
				break;	
		}
		printf("%d \n", enemy[i][0]);*/
		
	}
	
	glutSwapBuffers();

}
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50, 50, -50, 50, -50.0, 50.0);

	glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			move++;
			if (move > 4)move = 4;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			move--;
			if (move < 0)move = 0;
		}
		break;
	default:
		break;
	}
}

void init(void)
{
	//レーンの決定、乱数によって決定する。
	srand((unsigned int)time(NULL));
	for (int i=0; i < NUM; i++) {
		int a = rand() % 5;
		rn[i] = a;
		ex[i] = -50, ey[i] = 3;
		if (rn[i] == 0) {
			ez[i] = -20;
		}
		else if (rn[i] == 1) {
			ez[i] = -10;
		}
		else if (rn[i] == 2) {
			ez[i] = 0;
		}
		else if (rn[i] == 3) {
			ez[i] = 10;
		}
		else if (rn[i] == 4) {
			ez[i] = 20;
		}
	}
	glClearColor(0, 0, 0.9, 1.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);//エッジがわかるようにカリングを設定
	glCullFace(GL_FRONT);

}

int main(int argc, char *argv[])
{
	glutInitWindowSize(450, 400);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutIdleFunc(idle);//動作統括
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	init();
	/*デバッグ用表示
	srand((unsigned int)time(NULL));
	for (int i = 0; i < NUM; i++) {
		int a = rand() % 5;
		rn[i] = a;
		if (rn[i] == 5)rn[i] = 0;
		ex[i] = -50, ey[i] = 3;
		if (a== 0) {
			ez[i] = -20;
		}
		else if (a == 1) {
			ez[i] = -10;
		}
		else if (a == 2) {
			ez[i] = 0;
		}
		else if (a == 3) {
			ez[i] = 10;
		}
		else if (a == 4) {
			ez[i] = 20;
		}
		printf("%d %d %d \n", a, rn[i], count);
	}*/
	glutMainLoop();
	return 0;
}