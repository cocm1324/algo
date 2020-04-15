class Twitter:
	def __init__(self):
		self.seq = 0
		self.tweetData = dict()
		self.followData = dict()

	def postTweet(self, userId, tweetId):
		if not (userId in self.followData):
			self.followData[userId] = [userId]
		if not (userId in self.tweetData):
			self.tweetData[userId] = []
		self.tweetData[userId].insert(0, (self.seq, tweetId))
		self.seq += 1

	def getNewsFeed(self, userId):
		if not (userId in self.followData):
			return []
		feeds = []
		for followee in self.followData[userId]:
			if not (followee in self.tweetData):
				continue
			feeds += self.tweetData[followee][0:10]
		feeds.sort(key=lambda el: -el[0])
		return list(map(lambda el: el[1], feeds[0:10]))

	def follow(self, followerId, followeeId):
		if not (followerId in self.followData):
			self.followData[followerId] = [followerId]
		if not (followeeId in self.followData[followerId]):
			self.followData[followerId].append(followeeId)

	def unfollow(self, followerId, followeeId):
		if followerId == followeeId:
			return
		if not (followerId in self.followData):
			return
		if not (followeeId in self.followData[followerId]):
			return
		self.followData[followerId].remove(followeeId)

# inserting is fast, bottleneck is getNewsFeed(getting data)

# i think to optimize get news feed, key of ds can be userId
# -> tweet is dict(key=userId, value=tweets of the user)
# -> follow is dict(key=userId(follower), value=followee of the user)

# getNewsFeed:
#	get followees <--(1)
#	get tweets arrays of (1) from tweet <--(2)
#	merge all arrays from (2) and sort by bigger seq <--(3)
#	return (3)[0:10]

obj = Twitter()

obj.postTweet(1, 5)
obj.follow(1, 2)
obj.follow(2, 1)
print(obj.getNewsFeed(2))
obj.postTweet(2, 6)
print(obj.getNewsFeed(1))
print(obj.getNewsFeed(2))
obj.unfollow(2, 1)
print(obj.getNewsFeed(1))
print(obj.getNewsFeed(2))
obj.unfollow(1, 2)
print(obj.getNewsFeed(1))
print(obj.getNewsFeed(2))


for key in obj.followData:
	print(key, obj.followData[key])
print('---------------')
for key in obj.tweetData:
	print(key, obj.tweetData[key])
