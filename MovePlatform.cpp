//UE5中移动平台基础功能移动的实现
//在类中声名
void MovePlatform(float DeltaTime);

UPROPERTY(EditAnywhere)//可以直接在UE5中修改PlatformVelocity的值
FVector PlatformVelocity = FVector(0.0f, 0.0f, 0.0f);

//Tick每一帧调用一次这个函数
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);//DeltaTime增量时间：每秒/每秒帧数
	MovePlatform(DeltaTime);
}

//移动平台的移动具体实现
void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector Location = GetActorLocation();
	Location = Location + (PlatformVelocity * DeltaTime);
	SetActorLocation(Location);
}