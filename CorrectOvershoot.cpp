

void MovePlatform(float DeltaTime);
//设定一个类中拥有x，y，z的初始值，改变这些值来达到向x，y，z方向移动
UPROPERTY(EditAnywhere)
FVector PlatformVelocity = FVector(0.0f, 0.0f, 0.0f);
//移动速度初始值100
UPROPERTY(EditAnywhere)
float MoveDistance = 100.0f;
//移动距离
UPROPERTY(VisibleAnywhere)
float DistanceMoved = 0.0f;



void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector Location = GetActorLocation();
	Location = Location + (PlatformVelocity * DeltaTime);
	SetActorLocation(Location);
	DistanceMoved = FVector::Dist(StartLocation, Location);
	if (DistanceMoved >= MoveDistance)
	{
		//改变反向与初始位置来实现平台来回移动
		PlatformVelocity = -PlatformVelocity;
		StartLocation = Location;
		//但是这样做实际移动距离会微大于我们的设置距离
		//游戏时间运行久了就会导致位置偏移也就是过冲
	}
}
//修正过冲
if (DistanceMoved >= MoveDistance)
{
	//改变反向与初始位置来实现平台来回移动
	//GetSafeNormal()可以返回移动方向
	FVector MoveDirection = PlatformVelocity.GetSafeNormal();
	//移动方向*移动距离
	FVector NewStartLocation = StartLocation + MoveDistance * MoveDirection;
	SetActorLocation(NewStartLocation);
	StartLocation = NewStartLocation;

	PlatformVelocity = -PlatformVelocity;
