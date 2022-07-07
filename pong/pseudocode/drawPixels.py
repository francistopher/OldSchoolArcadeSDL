def drawBallLayers(position, radius, currentRadius, direction, subLayerLen, layerLen, subLayerX, layerX=0):
	if layerX != layerLen:
		print("Draw pos x:", position[0], "pos y:", position[1], "LayerLen", layerLen)
	if subLayerLen == subLayerX:
		print("SubLayerLan:", subLayerLen)
		direction+=1
		subLayerX = 0
	if layerX == layerLen:
		position[0] += subLayerLen - 1
		drawBall(position, radius, currentRadius)
	else:
		direction %= 4
		if direction == 0:
			position[0] += 1
		elif direction == 1:
			position[1] -= 1
		elif direction == 2:
			position[0] -= 1
		elif direction == 3:
			position[1] += 1
		drawBallLayers(position, radius, currentRadius, direction, subLayerLen, layerLen,  subLayerX + 1, layerX + 1)
	

def drawBall(position, radius, currentRadius=1):
	print("NEW LAYER")
	if currentRadius < radius + 1:
		print("Draw pos x:", position[0], "pos y:", position[1])
		position[0] += 1
		drawBallLayers(position, radius, currentRadius + 1, 1, currentRadius * 2, 8 * (currentRadius), 1)



position = [312, 312]
radius = 2
drawBall(position, radius)


