class TimelineEventFile < ApplicationRecord
  belongs_to :timeline_event
  has_one_attached :file_as

  mount_uploader :file, TimelineEventFileUploader

  validates :file_as, attached: true

  # File is stored as private on S3. So we need to retrieve the name another way; not the usual column.file.filename.
  def filename
    file_as.filename
  rescue Errno::ENOENT => e
    raise e unless Rails.env.development?

    'missing_in_development'
  end

  def file_url
    file_as.attached? && Rails.application.routes.url_helpers.rails_blob_path(file_as, only_path: true)
  end

  def title
    file_as.metadata['title']
  end

  def private
    file_as.metadata['private']
  end
end
