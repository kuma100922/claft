/*�w�Дԍ��@1925059022
�����@�����n
�薼�@�e�������Q�[��

�g�p���@
�E�B���h�E���ォ��Ԃ���������Ă���̂ŁA������悯��Q�[���B
����̓}�E�X�{�^���ōs���B
�E�F�L�����N�^�[���E�Ɉړ��B
���F�L�����N�^�[�����Ɉړ��B
�����蔻��⓾�_�̕\���Ȃǂ͂Ȃ��B�i��肽���������ǁj
�e����NUM�̐������o�Ă���B

�H�v�����_
�L�����N�^�[�����[���̊O�ɍs���Ȃ��悤�ɁA�v���O���������������ƁB
�󋵂����₷���悤�ɁA���_��ς������ƁB
���S�Ȑl�^�ł͂Ȃ����A�L�����N�^�[���K�w�\���ɂ���č쐬�������ƁB
�}�N���Œ�`���Ă���SPEED�̒l��ς��邱�ƂŁA�e���̑��x���ύX�ł���悤�ɂ������ƁB
���[���̉�]�̌������悭�킩��悤�ɁA�J�����O���g�p�������ƁB
�����ŁA�e���̗�������߂��̂ŁA�΂肪����Ƃ��Ă��A�Q�[�����͍��܂��Ă���ƍl����B

�����������_
�X�R�A�\�����ƃQ�[���̏I���̋@�\��t�������������B
�e�e���́A�w���W�𐳂̌����œ����A���[���ɏ��O�ɁA�y���W�͈�ӂɌ��肷��B
���������āA�L�����N�^�[�̂w���W�ƃ��[���ԍ�����v����΁A�����蔻��̈��Ƃ��āA���Q�[����
�����߂�ꂽ�ƍl����B
����ɏ]���āA�ϐ�score�ƕϐ�count���g�p���邱�Ƃ��l�����B
�e�ϐ��̖����͈ȉ��̒ʂ�ł���B
score�F�e�����悯���ہA�P���Z�����B����āAscore�̍ő�l��NUM�ł���B
count�F�e���ɂ��������ۂɂP���Z����Bcount>=3�ŃQ�[�����I�����Ȃ킿glTranslated(r,0,0)�̓��������[�v���u���C�N����B
*/
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#define NUM 200//�e���̐�
#define SPEED 5//�e���̃X�s�[�h
int move=2;//�L�����N�^�[�̓����𓝊�����ϐ��B�Q�͐^�񒆂̃��[�����w���B
double cos30 = 1.7320508 / 2;
//int score = 0;
//int count = 0;
int enemy[NUM][3];//�e���̍��W
int ex[NUM],ey[NUM], ez[NUM];//����p�̔z��
int rn[NUM];//�e�e���̃��[���ԍ�������O�C�P�C�Q�C�R�C�S�Ƃ���B
int r=0;//�ړ�����
void idle(void) {
	glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(7, 8, 5, 0, 0, 0, 0, 1, 0);
	glPushMatrix();
	glTranslated(0, 0, -20);//��ƂȂ郌�[���̕`��
	glPushMatrix();
	glColor3d(0.2, 0.2, 0.2);
	glScaled(100, 1, 2);
	glutSolidCube(4);
	glColor3d(1, 1, 1);
	glutWireCube(4);
	glPopMatrix();
	for (int i = 0; i < 4; i++) {
		glTranslated(0, 0, 10);//�c��S�̃��[���̕`��
		glPushMatrix();
		glColor3d(0.2, 0.2, 0.2);
		glScaled(100, 1, 2);
		glutSolidCube(4);
		glColor3d(1, 1, 1);
		glutWireCube(4);
		glPopMatrix();
	}
	glTranslated(0, 0, 10*(move-2));
	glTranslated(45, 6 + 5 * cos30, -20);//�_�l�Ԃ̓��̒��S�̍���
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
	glutSolidCube(1);//����
	glPopMatrix();
	glRotated(30, 1, 0, 0);
	glTranslated(0, -5, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1);//�r
	glPopMatrix();
	glRotated(-30, 1, 0, 0);
	glTranslated(0, -5, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1);//�r
	glPopMatrix();
	glTranslated(0, -2.5, 0);
	glColor3d(1, 1, 0);
	glRotated(30, 1, 0, 0);
	glScaled(1, 5, 1);
	glutSolidCube(1);//��
	glPopMatrix();
	glRotated(-30, 1, 0, 0);
	glTranslated(0, -5, 0);
	glScaled(1, 4, 1);
	glutSolidCube(1);//��
	glPopMatrix();
	glPopMatrix();

	glTranslated(0, 6, 0);
	r++;
	for (int j = 0; j < SPEED; j++) {
		glTranslated(r, 0, 0);
	}
	
	for (int i = 0; i < NUM; i++) {//�ˏo�̊Ԋu
		glTranslated(-10, 0, 0);
		glPushMatrix();
		glTranslated(0, 0, (GLdouble)ez[i]);//�e���̏�郌�[���̌���
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
	//���[���̌���A�����ɂ���Č��肷��B
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
	glEnable(GL_CULL_FACE);//�G�b�W���킩��悤�ɃJ�����O��ݒ�
	glCullFace(GL_FRONT);

}

int main(int argc, char *argv[])
{
	glutInitWindowSize(450, 400);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutIdleFunc(idle);//���쓝��
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	init();
	/*�f�o�b�O�p�\��
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